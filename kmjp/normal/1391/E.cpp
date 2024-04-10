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
int N,M;
vector<int> E[505050];

int id[505050];
int D[505050];
int P[505050];
int cand[505050];
int vis[505050];

void dfs(int cur,int pre,int id,int d) {
	if(vis[cur]) return;
	vis[cur]=1;
	P[cur]=pre;
	D[cur]=d;
	if(D[cand[id]]<d) cand[id]=cur;
	FORR(e,E[cur]) if(vis[e]==0) dfs(e,cur,id,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			D[i]=0;
			cand[i]=0;
			vis[i]=0;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		vector<pair<int,int>> V;
		V.push_back({0,0});
		V.push_back({0,0});
		vis[0]=1;
		FORR(e,E[0]) {
			dfs(e,0,e,1);
			V.push_back({D[cand[e]],cand[e]});
		}
		sort(ALL(V));
		reverse(ALL(V));
		vector<int> R,R2;
		int cur=V[0].second;
		while(cur!=0) {
			R.push_back(cur);
			cur=P[cur];
		}
		R.push_back(0);
		cur=V[1].second;
		while(cur!=0) {
			R2.push_back(cur);
			cur=P[cur];
		}
		reverse(ALL(R2));
		FORR(r,R2) R.push_back(r);
		if(2*R.size()>=N) {
			cout<<"PATH"<<endl;
			cout<<R.size()<<endl;
			FORR(r,R) cout<<r+1<<" ";
			cout<<endl;
		}
		else {
			FOR(i,N) vis[i]=-1;
			R.clear();
			FOR(i,N) {
				if(vis[D[i]]==-1) {
					vis[D[i]]=i;
				}
				else {
					R.push_back(i);
					R.push_back(vis[D[i]]);
					vis[D[i]]=-1;
				}
			}
			
			cout<<"PAIRING"<<endl;
			cout<<R.size()/2<<endl;
			FOR(i,R.size()/2) {
				cout<<R[i*2]+1<<" "<<R[i*2+1]+1<<endl;
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}