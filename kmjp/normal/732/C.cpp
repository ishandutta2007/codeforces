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

ll A,B,C;

ll dodo(ll a,ll b,ll c) {
	ll d=max(0LL,max(A-a,max(B-b,C-c)));
	return (d+a-A)+(d+b-B)+(d+c-C);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	ll mi=1LL<<62;
	FOR(i,8) mi=min(mi,dodo(i/4,i/2%2,i%2));
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}