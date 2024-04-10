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

ll N,S;
ll F[101010],G[101010];

ll num[101010],ma[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	F[1]=G[1]=N*(N+1)/2;
	
	if(S==F[1]) {
		cout<<"Yes"<<endl;
		for(i=2;i<=N;i++) cout<<(i-1)<<" ";
		cout<<endl;
		return;
	}
	
	for(i=2;i<=N-1;i++) {
		int d=1;
		ll C=1;
		ll lef=N;
		
		while(lef>0) {
			ll num=min(C,lef);
			F[i]+=num*d;
			lef-=num;
			d++;
			C*=i;
		}
		
		G[i]=(N-i)*(N-i+1)/2+i*(N-i+1);
		if(F[i]<=S && S<=G[i]) break;
	}
	
	if(i==N) return _P("No\n");
	ll K=i;
	
	for(i=1;i<=N-K;i++) {
		num[i]=1, S-=i;
		if(i==1) ma[i]=1;
		else ma[i]=min(ma[i-1]*K,1LL<<40);
	}
	num[N-K+1]=K;
	S=K*(N-K+1)-S;
	x=N-K+1;
	
	while(S>0) {
		while(num[x]==0) x--;
		num[x]--;
		
		if(S<x && num[x-S]<ma[x-S]) {
			num[x-S]++;
			S=0;
		}
		else {
			for(i=1;i<=N;i++) if(num[i]<ma[i] && x-i<=S) {
				num[i]++;
				S-=(x-i);
				break;
			}
		}
	}
	
	cout<<"Yes"<<endl;
	int p=1;
	for(i=2;i<=N;i++) {
		
		FOR(j,num[i]) cout<<p+(j/K)<<" ";
		p+=num[i-1];
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}