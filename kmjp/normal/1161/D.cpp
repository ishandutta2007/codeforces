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
string S;
ll mo=998244353;

int vis[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	reverse(ALL(S));
	N=S.size();
	
	if(S[0]=='1') return _P("0\n");
	S[0]='0';
	
	
	ll ret=0;
	
	for(i=1;i<N;i++) {
		ZERO(vis);
		int num=0;
		ll pat=1;
		for(x=N-1;x>=0;x--) if(vis[x]==0) {
			assert(x>=i);
			int mask=3;
			if(S[x]=='1') mask=2;
			if(S[x]=='0') mask=1;
			
			// par first
			y=x;
			while(1) {
				vis[y]=1;
				if(y==N-1-y) break;
				
				y=N-1-y;
				vis[y]=1;
				
				if(y>=i) {
					if(S[y]=='1') mask&=2;
					if(S[y]=='0') mask&=1;
					break;
				}
				
				if(S[y]=='1' && (mask==1||mask==2)) mask=3-mask;
				if(S[y]=='?') {
					pat=pat*__builtin_popcount(mask)%mo;
					mask=3;
				}
				
				
				if(y==i-1-y) break;
				
				y=i-1-y;
				if(S[y]=='1' && (mask==1||mask==2)) mask=3-mask;
				
				if(S[y]=='?') {
					pat=pat*__builtin_popcount(mask)%mo;
					mask=3;
				}
			}
			pat=pat*__builtin_popcount(mask)%mo;
		}
		ret+=pat;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}