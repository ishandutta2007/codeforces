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

int N;
vector<int> E[202020];
ll mo=998244353;
ll fact[202020];

ll dfs(int cur,int pre) {
	ll ret=1;
	int num=0;
	FORR(e,E[cur]) if(e!=pre) {
		num++;
		ret=ret*dfs(e,cur)%mo;
	}
	
	if(cur!=0) ret=ret*fact[num]%mo*(num+1)%mo;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	fact[0]=1;
	for(i=1;i<=200020;i++) fact[i]=fact[i-1]*i%mo;
	
	cout<<(N*dfs(0,0)%mo*fact[E[0].size()]%mo)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}