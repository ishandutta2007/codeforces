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
vector<int> E[303030];

int ma;
int dfs(int cur,int pre) {
	vector<int> V;
	FORR(e,E[cur]) if(e!=pre) V.push_back(dfs(e,cur));
	sort(ALL(V));
	reverse(ALL(V));
	
	if(V.size()>=2) {
		ma=max(ma,(int)(V[0]+V[1]+1+V.size()-2+(pre!=-1)));
		return V[0]+1+V.size()-1;
	}
	else if(V.size()==1) {
		ma=max(ma,V[0]+1);
		return V[0]+1;
	}
	else {
		if(pre!=-1) ma=max(ma,2);
		return 1;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		ma=1;
		dfs(0,-1);
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}