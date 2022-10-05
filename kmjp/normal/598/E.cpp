#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;

ll memo[31][31][51];

ll dodo(int a,int b,int k) {
	
	if(a*b==k || k==0) return 0;
	if(a*b<k) return 1LL<<60;
	if(a<b) swap(a,b);
	
	ll& ret=memo[a][b][k];
	if(memo[a][b][k]>=0) return memo[a][b][k];
	
	ret=1LL<<60;
	
	for(int w=1;w<=a/2;w++) {
		for(int d=0;d<=k;d++) {
			ret=min(ret,0LL+b*b+dodo(w,b,d)+dodo(a-w,b,k-d));
		}
	}
	for(int h=1;h<=b/2;h++) {
		for(int d=0;d<=k;d++) {
			ret=min(ret,0LL+a*a+dodo(a,h,d)+dodo(a,b-h,k-d));
		}
	}
	
	
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	for(y=1;y<=30;y++) for(x=1;x<=30;x++) for(k=1;k<=min(50,x*y);k++) dodo(y,x,k);
	
	cin>>i;
	while(i--) {
		cin>>x>>y>>r;
		cout<<dodo(x,y,r)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}