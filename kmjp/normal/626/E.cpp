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
int A[202020];
ll S[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[i];
	
	ll bp=0,br=1;
	int M=0,num=0;
	
	for(i=1;i<N-1;i++) {
		int L=0,R=i;
		while(L+3<R) {
			int M1=(L*2+R)/3;
			int M2=(L+R*2)/3;
			ll m1p=S[i+1]-S[i-M1]+S[N]-S[N-M1]-1LL*A[i]*(2*M1+1);
			ll m2p=S[i+1]-S[i-M2]+S[N]-S[N-M2]-1LL*A[i]*(2*M2+1);
			if(m1p*(2*M2+1)>m2p*(2*M1+1)) R=M2;
			else L=M1;
		}
		
		for(x=L;x<=R;x++) {
			ll tp=S[i+1]-S[i-x]+S[N]-S[N-x]-1LL*A[i]*(2*x+1);
			ll tr=2*x+1;
			if(tp*br>bp*tr) bp=tp, br=tr, M=i, num=x;
		}
		
	}
	
	cout<<(1+num*2)<<endl;
	for(i=M-num;i<=M;i++) cout<<A[i]<<" ";
	FOR(i,num) cout<<A[N-num+i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}