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
ll K;
ll A[101010];
ll B[101010];
ll C[101010];

ll num(ll v) {
	int i,j;
	ll sum=0;
	FOR(i,N) {
		B[i]=0;
		for(j=30;j>=0;j--) if(B[i]+(1<<j)<=A[i]) {
			ll t=B[i]+(1<<j);
			ll d=A[i]-3*t*t+3*t-1;
			if(d>=v) B[i]+=1<<j;
		}
		
		sum+=B[i];
	}
	return sum;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	
	ll mi=-1LL<<62;
	for(i=62;i>=0;i--) {
		if(num(mi+(1LL<<i))>=K) mi+=1LL<<i;
	}
	/*
	
	priority_queue<pair<ll,int>> Q;
	
	ll sum=0;
	FOR(i,N) {
		D[i]=A[i]-1;
		Q.push({D[i],i});
	}
	while(K--) {
		assert(Q.size());
		x=Q.top().second;
		Q.pop();
		sum+=D[x];
		B[x]++;
		if(B[x]<A[x]) {
			D[x]=A[x]-3*B[x]*(B[x]+1)-1;
			Q.push({D[x],x});
		}
	}
	*/
	
	K=num(mi)-K;
	FOR(i,N) {
		if(K&&B[i]&&(A[i]-3*B[i]*B[i]+3*B[i]-1)==mi) {
			B[i]--;
			K--;
		}
		cout<<B[i]<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}