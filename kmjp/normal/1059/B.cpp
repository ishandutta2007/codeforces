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

int H,W;
string S[1010];
string T[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		T[y]=string(W,'.');
	}
	
	for(y=1;y<H-1;y++) {
		for(x=1;x<W-1;x++) {
			int fill=1;
			for(int dy=y-1;dy<=y+1;dy++) {
				for(int dx=x-1;dx<=x+1;dx++) {
					if((dy!=y || dx!=x) && S[dy][dx]=='.') fill=0;
				}
			}
			if(fill) {
				for(int dy=y-1;dy<=y+1;dy++) {
					for(int dx=x-1;dx<=x+1;dx++) {
						if((dy!=y || dx!=x)) T[dy][dx]='#';
					}
				}
			}
		}
	}
	
	FOR(y,H) if(S[y]!=T[y]) return _P("NO\n");
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}