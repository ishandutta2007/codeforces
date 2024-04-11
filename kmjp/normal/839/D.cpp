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
ll A[202020];
ll mo=1000000007;

ll num[1010100];
ll p[1010100];
ll p2[1010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		for(x=1;x*x<=A[i];x++) if(A[i]%x==0) {
			num[x]++;
			if(x*x!=A[i]) num[A[i]/x]++;
		}
	}
	
	p2[0]=1;
	for(i=1;i<=1000000;i++) p2[i]=p2[i-1]*2%mo;
	
	ll tot=0;
	for(i=1000000;i>=2;i--) if(num[i]) {
		p[i]=num[i]*p2[num[i]-1]%mo;
		for(j=i*2;j<=1000000;j+=i) p[i]-=p[j];
		p[i]=(p[i]%mo+mo)%mo;
		(tot+=p[i]*i)%=mo;
	}
	cout<<tot<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}