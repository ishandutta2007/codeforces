#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N;
int X[10101],Y[10101];
int C[4][4][4];
int R[6060][6060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) R[x][y]=gcd(abs(X[x]-X[y]),abs(Y[x]-Y[y]))%4;
	
	ll p3=0,p1=0;
	FOR(x,N) {
		X[x]%=4;
		Y[x]%=4;
		ZERO(C);
		FOR(y,N) if(x!=y) C[X[y]%4][Y[y]%4][R[x][y]]++;
			
		int x1,y1,b1,x2,y2,b2;
		FOR(x1,4) FOR(y1,4) FOR(b1,4) FOR(x2,4) FOR(y2,4) FOR(b2,4) {
			ll pat=0;
			if(x1==x2&&y1==y2&&b1==b2) {
				pat=C[x1][y1][b1]*(C[x2][y2][b2]-1);
			}
			else {
				pat=C[x1][y1][b1]*(C[x2][y2][b2]);
			}
			if(x1%2!=x2%2) continue;
			if(y1%2!=y2%2) continue;
			int b3;
			if(x1==x2&&y1==y2) b3=0;
			else b3=2;
			
			int bp=(b1+b2+b3)%4;
			int a=abs(X[x]*y1-Y[x]*x1+x1*y2-y1*x2+x2*Y[x]-y2*X[x])%4;
			
			if(a==bp) {
				if(b1%2==0&&b2%2==0) p3+=pat;
				else p1+=pat;
			}
		}
	}
	
	cout<<(p3/3+p1)/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}