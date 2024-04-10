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
vector<int> E[2505050];
string S;
int P[2505050];
int C[2];

void dfs(int cur,int col,int pre) {
	if(E[cur].size()==3) C[col]++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,col^1,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,4*N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		cin>>S;
		int ok=0;
		x=N;
		FOR(i,N) if(S[i]=='W') {
			E[i].push_back(x);
			E[x].push_back(i);
			E[x].push_back(x+1);
			E[x].push_back(x+2);
			E[x+1].push_back(x);
			E[x+2].push_back(x);
			x+=3;
		}
		N=x;
		FOR(i,N) {
			if(E[i].size()>=4) ok=1;
			if(E[i].size()>=3) {
				int num=0;
				FORR(e,E[i]) if(E[e].size()>=2) num++;
				if(num>=2) ok=1;
			}
		}
		C[0]=C[1]=0;
		dfs(0,0,-1);
		if(C[0]>=2 || C[1]>=2) ok=1;
		
		
		if(ok) {
			cout<<"White"<<endl;
		}
		else {
			cout<<"Draw"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}