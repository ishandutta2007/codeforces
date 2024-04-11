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

int N,K,Q;
int ok[202020];
int sum[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) {
		int L,R;
		cin>>L>>R;
		ok[L]++;
		ok[R+1]--;
	}
	for(i=1;i<=200000;i++) {
		ok[i]+=ok[i-1];
		sum[i]=sum[i-1]+(ok[i]>=K);
	}
	FOR(i,Q) {
		int L,R;
		cin>>L>>R;
		cout<<sum[R]-sum[L-1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}