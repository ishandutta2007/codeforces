#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int T;
int N;
vector<int> E[202];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int num[202]={};
		int inval[202]={};
		FOR(i,N-1) {
			E[i].clear();
			cin>>x;
			FOR(j,x) {
				cin>>y;
				num[y]++;
				E[i].push_back(y);
			}
		}
		/*
		if(T==28 && E[0].size()==3) {
			FOR(i,N-1) {
				cout<<"!";
				FORR(e,E[i]) cout<<e;
				cout<<endl;
			}
		}*/
		vector<int> cand;
		for(i=1;i<=N;i++) if(num[i]==1) cand.push_back(i);
		if(cand.size()==1) cand.push_back(0);
		while(1) {
			int ri[202];
			vector<int> V;
			ll ret=0;
			ZERO(inval);
			for(j=1;j<=N;j++) ret+=j, num[j]=0,ri[j]=N;
			FOR(j,N-1) FORR(e,E[j]) num[e]++;
			
			vector<int> order;
			while(V.size()<N-1) {
				
				vector<int> cand2;
				for(j=1;j<=N;j++) if(num[j]==1 && j!=cand[1]) cand2.push_back(j);
				/*
				FORR(v,V) cout<<v;
				cout<<"    ";
				FORR(c,cand2) cout<<c;
				cout<<endl;*/
				if(cand2.empty()) goto out;
				if(cand2.size()==2) {
					if(ri[cand2[0]]<ri[cand2[1]]) j=cand2[0];
					else j=cand2[1];
				}
				else {
					j=cand2[0];
				}
				
				V.push_back(j);
				ret-=j;
				FOR(x,N-1) if(inval[x]==0 && count(ALL(E[x]),j)) {
					//cout<<"!!"<<x<<endl;
					order.push_back(x);
					FORR(e,E[x]) {
						num[e]--;
						ri[e]=min(ri[e],(int)(V.size()+E[x].size()-2));
					}
					inval[x]=1;
				}
				//cout<<"!"<<V.size()<<order.size()<<endl;
				assert(V.size()==order.size());
			}
			
			V.push_back(ret);
			FOR(j,N-1) {
				vector<int> W;
				if(j+E[order[j]].size()>N) break;
				FOR(x,E[order[j]].size()) W.push_back(V[j+x]);
				sort(ALL(W));
				if(W!=E[order[j]]) break;
				
			}
			if(j==N-1) {
				reverse(ALL(V));
				FORR(v,V) cout<<v<<" ";
				cout<<endl;
				break;
			}
			out:
			swap(cand[0],cand[1]);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}