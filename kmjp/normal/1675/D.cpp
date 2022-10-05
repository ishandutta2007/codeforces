#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
int P[202020];
vector<int> E[202020];
int in[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+1) E[i].clear();
		int root;
		FOR(i,N) {
			cin>>P[i+1];
			if(i+1==P[i+1]) root=i+1;
			else E[P[i+1]].push_back(i+1);
		}
		
		vector<vector<int>> path;
		queue<int> Q;
		Q.push(root);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			vector<int> P;
			while(1) {
				P.push_back(cur);
				if(E[cur].empty()) {
					break;
				}
				for(i=1;i<E[cur].size();i++) Q.push(E[cur][i]);
				cur=E[cur][0];
			}
			path.push_back(P);
		}
		cout<<path.size()<<endl;
		FORR(p,path) {
			cout<<p.size()<<endl;
			FORR(v,p) cout<<v<<" ";
			cout<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}