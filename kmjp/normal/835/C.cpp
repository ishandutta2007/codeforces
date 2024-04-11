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

int N,Q,C;
int S[102][102][12];
int X1,Y1,X2,Y2,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>C;
	FOR(i,N) {
		cin>>x>>y>>r;
		S[y][x][r]++;
	}
	FOR(i,C+1) {
		for(y=1;y<=100;y++) for(x=1;x<=100;x++) {
			S[y][x][i] = S[y][x][i]+S[y-1][x][i]+S[y][x-1][i]-S[y-1][x-1][i];
		}
	}
	
	
	
	
	while(Q--) {
		cin>>T>>X1>>Y1>>X2>>Y2;
		X1--,Y1--;
		
		ll ret=0;
		FOR(i,C+1) {
			x=S[Y2][X2][i]-S[Y1][X2][i]-S[Y2][X1][i]+S[Y1][X1][i];
			ret += x*((i+T)%(C+1));
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