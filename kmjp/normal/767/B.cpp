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


ll S,F,T;
int N;
ll A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>F>>T>>N;
	ll p=S;
	FOR(i,N) {
		cin>>A[i];
		B[i]=max(p,A[i]);
		p=B[i]+T;
	}
	if(A[0]>S) {
		cout<<S<<endl;
	}
	else if(B[N-1]+2*T<=F) {
		cout<<F-T<<endl;
	}
	else {
		ll ret=A[0]-1,hoge=S-ret;
		
		FOR(i,N-1) {
			ll c=A[i+1]-1;
			ll w=B[i]+T-c;
			if(w<hoge && B[i]+2*T<=F) ret=c,hoge=w;
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}