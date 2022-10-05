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

ll p10[22];
ll F[22],G[22];

int Q;
ll K;

char hoge(ll K) {
	int i;
	for(i=1;i<=20;i++) {
		if(K<=(p10[i]-p10[i-1])*i) {
			K--;
			ll v=p10[i-1]+K/i;
			string S=to_string(v);
			return S[K%i];
			
		}
		K-=(p10[i]-p10[i-1])*i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,20) p10[i+1]=p10[i]*10;
	
	for(i=1;i<=18;i++) {
		ll num=p10[i]-p10[i-1];
		F[i]=F[i-1]+i*num;
		G[i]=G[i-1]+F[i-1]*(p10[i]-p10[i-1])+i*num*(num+1)/2;
		
	}
	cin>>Q;
	while(Q--) {
		cin>>K;
		int d;
		for(d=1;d<=9;d++) if(K<=G[d]) break;
		K-=G[d-1];
		ll num=p10[d]-p10[d-1];
		ll s=num;
		for(i=30;i>=0;i--) if(s-(1<<i)>=1) {
			ll t=s-(1<<i);
			ll len=F[d-1]*t+d*t*(t+1)/2;
			if(len>=K) s-=1<<i;
		}
		
		s--;
		K-=F[d-1]*s+d*s*(s+1)/2;
		cout<<hoge(K)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}