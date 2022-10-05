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
ll N,K;

ll num[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=31;i++) {
		num[i]=1+4*num[i-1];
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		N--;
		if(N>=31) {
			cout<<"YES "<<N<<endl;
			continue;
		}
		ll a=2,b=1;
		ll L=1,R=1+num[N];
		while(N>=0) {
			if(L<=K && K<=R) {
				cout<<"YES "<<N<<endl;
				break;
			}
			N--;
			if(N<0) {
				cout<<"NO"<<endl;
				break;
			}
			L+=(a+b);
			R+=(a+b)+(2*a+b)*num[N];
			a=2*a+2;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}