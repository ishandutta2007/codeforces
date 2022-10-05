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

int T,H;
vector<int> nei[200];
vector<int> path;
int HH[200];
int root;


void ask(int v) {
	if(nei[v].size()) return;
	
	int n,x;
	cout<<"? "<<v<<endl;
	cin>>n;
	if(n==2) root=v;
	while(n--) cin>>x, nei[v].push_back(x);
	
}

int dfs(int cur,vector<int>& P) {
	ask(cur);
	P.push_back(cur);
	if(nei[cur].size()<=2) return 1;
	FORR(r,nei[cur]) if(r!=P[P.size()-2]) return dfs(r,P);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H;
		root=0;
		FOR(i,200) nei[i].clear(),HH[i]=0;
		
		vector<int> P,Q;
		int par;
		ask(1);
		if(nei[1].size()==2) {
			goto out;
		}
		else if(nei[1].size()==1) {
			HH[1]=H;
			P.push_back(1);
		}
		else if(nei[1].size()==3) {
			P.push_back(1);
			dfs(nei[1][0],P);
			reverse(ALL(P));
			Q.push_back(1);
			dfs(nei[1][1],Q);
			if(root) goto out;
			for(i=1;i<Q.size();i++) P.push_back(Q[i]);
			FOR(i,P.size()/2+1) HH[P[i]]=HH[P[P.size()-1-i]]=H-i;
			P.resize(P.size()/2+1);
		}
		
		int nex;
		while(HH[P.back()]>4) {
			FORR(r,nei[P.back()]) if(HH[r]==0) nex=r;
			Q.clear();
			Q.push_back(P.back());
			dfs(nex,Q);
			if(root) goto out;
			
			for(i=1;i<Q.size();i++) P.push_back(Q[i]);
			FOR(i,P.size()/2+1) HH[P[i]]=HH[P[P.size()-1-i]]=H-i;
			P.resize(P.size()/2+1);
		}
		
		if(root) goto out;
		
		
		FORR(r,nei[P.back()]) if(HH[r]==0) nex=r;
		HH[nex]=HH[P.back()]-1;
		if(HH[nex]==1) {
			root=nex;
		}
		else {
			vector<int> cand;
			
			ask(nex);
			if(HH[nex]==2) {
				FORR(x,nei[nex]) if(HH[x]==0) cand.push_back(x);
			}
			else if(HH[nex]==3) {
				FORR(x,nei[nex]) if(HH[x]==0) {
					HH[x]=1;
					ask(x);
					FORR(r,nei[x]) if(HH[r]==0) cand.push_back(r);
				}
			}
			root=cand.back();
			cand.pop_back();
			FORR(x,cand) ask(x);
		}
out:
		cout<<"! "<<root<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}