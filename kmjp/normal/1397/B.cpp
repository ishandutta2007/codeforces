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
ll A[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll mi=0;
	FOR(i,N) {
		cin>>A[i];
		mi+=A[i]-1;
	}
	sort(A,A+N);
	for(ll a=2;a<=1000000;a++) {
		ll sum=0;
		ll cur=1;
		FOR(i,N) {
			sum+=abs(cur-A[i]);
			if(sum>=mi) break;
			cur=cur*a;
		}
		mi=min(mi,sum);
		
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}