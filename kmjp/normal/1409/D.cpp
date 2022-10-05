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
ll N,S;
ll ret;
ll p10[20];

ll num[167];

void dfs(int d,int sum,ll v) {
	if(d<0) {
		if(sum<=S) ret=min(ret,v);
		return;
	}
	if(sum>S) return;
	
	ll cur=N/p10[d]%10;
	int i;
	for(i=cur+1;i<=9;i++) {
		int mi=sum+i;
		
		if(S>=mi) ret=min(ret,v+i*p10[d]);
	}
	
	v+=cur*p10[d];
	sum+=cur;
	dfs(d-1,sum,v);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,18) p10[i+1]=p10[i]*10;
	
	for(i=1;i<=166;i++) {
		j=i;
		FOR(x,19) {
			y=min(j,9);
			j-=y;
			num[i]+=y*p10[x];
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		ret=1LL<<60;
		dfs(18,0,0);
		cout<<ret-N<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}