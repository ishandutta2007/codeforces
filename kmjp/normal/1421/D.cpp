#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
ll X,Y;
ll C[6];
ll pat[3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>Y;
		FOR(i,6) cin>>C[i];
		FOR(x,3) FOR(y,3) pat[x][y]=1LL<<60;
		pat[2][2]=C[0];
		pat[1][2]=C[1];
		pat[0][1]=C[2];
		pat[0][0]=C[3];
		pat[1][0]=C[4];
		pat[2][1]=C[5];
		int x2,y2;
		FOR(i,8) {
			for(x=-1;x<=1;x++) for(y=-1;y<=1;y++) {
				for(x2=-1;x2<=1;x2++) for(y2=-1;y2<=1;y2++) {
					int tx=x+x2;
					int ty=y+y2;
					if(abs(tx)>=2) continue;
					if(abs(ty)>=2) continue;
					pat[1+tx][1+ty]=min(pat[1+tx][1+ty],pat[1+x][1+y]+pat[1+x2][1+y2]);
				}
			}
		}
		if(X<0) {
			FOR(y,3) swap(pat[2][y],pat[0][y]);
			X=-X;
		}
		if(Y<0) {
			FOR(x,3) swap(pat[x][2],pat[x][0]);
			Y=-Y;
		}
		ll ret=X*pat[2][1]+Y*pat[1][2];
		if(X<=Y) {
			// move X
			ret=min(ret,X*pat[2][2]+(Y-X)*pat[1][2]);
			// move Y
			ret=min(ret,Y*pat[2][2]+(Y-X)*pat[0][1]);
		}
		else {
			// move X
			ret=min(ret,X*pat[2][2]+(X-Y)*pat[1][0]);
			// move Y
			ret=min(ret,Y*pat[2][2]+(X-Y)*pat[2][1]);
		}
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}