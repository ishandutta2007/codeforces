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
vector<int> E[101010];
vector<int> X,Y;
int ok[2][1010];

int dfs(int cur,int pre) {
	if(ok[0][cur]) return cur;
	FORR(e,E[cur]) if(e!=pre) {
		int r=dfs(e,cur);
		if(r!=-1) return r;
	}
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,1001) E[i].clear();
		X.clear();
		Y.clear();
		ZERO(ok);
		cin>>N;
		FOR(i,N-1) {
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		cin>>x;
		FOR(i,x) {
			cin>>y;
			X.push_back(y);
			ok[0][y]=1;
		}
		cin>>x;
		FOR(i,x) {
			cin>>y;
			Y.push_back(y);
			ok[1][y]=1;
		}
		cout<<"B "<<Y[0]<<endl;
		cin>>x;
		if(ok[0][x]) {
			cout<<"C "<<x<<endl;
			continue;
		}
		x=dfs(x,-1);
		cout<<"A "<<x<<endl;
		cin>>y;
		if(ok[1][y]) {
			cout<<"C "<<x<<endl;
		}
		else {
			cout<<"C -1"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}