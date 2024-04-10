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

int N,SX,SY;
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>SX>>SY;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	int ma=0,RX=0,RY=0;
	for(x=max(0,SX-1);x<=min(SX+1,1000000000);x++) {
		for(y=max(0,SY-1);y<=min(SY+1,1000000000);y++) {
			if(x==SX && y==SY) continue;
			int num=0;
			FOR(i,N) {
				if(abs(SX-X[i])+abs(SY-Y[i])==abs(SX-x)+abs(x-X[i])+abs(SY-y)+abs(y-Y[i])) num++;
			}
			if(num>ma) ma=num, RX=x, RY=y;
		}
	}
	cout<<ma<<endl;
	cout<<RX<<" "<<RY<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}