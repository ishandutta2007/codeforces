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

ll S;
ll mo=1000000007;
ll N;
ll X[505050],Y[505050],SAY,SAX,SBX,SBY;

ll area(int a,int b,int c) {
	return ((X[c]-X[a])*(Y[b]-Y[a])-(Y[c]-Y[a])*(X[b]-X[a]));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	X[N]=X[0];
	Y[N]=Y[0];
	for(i=1;i<N-1;i++) S+=area(0,i,i+1);
	ll TS = S%mo*((N*(N-3)/2)%mo)%mo;
	
	ll A=0,TA=0;
	ll B=0,TB=0;
	FOR(x,N-3) {
		B+=area(0,N-2-x,N-1-x);
		(TB+=B%mo)%=mo;
	}
	
	SAX=X[0]+X[1];
	SAY=Y[0]+Y[1];
	for(x=2;x<N;x++) SBX+=X[x], SBY+=Y[x];
	y=1;
	FOR(x,N-1) {
		while(y+2<=N && (A+area(x,y,y+1))<=S/2) {
			A+=area(x,y,y+1);
			(TA+=A%mo)%=mo;
			(TB+=(mo-B%mo))%=mo;
			B-=area(x,y+1,y+2);
			y++;
			SAX+=X[y];
			SAY+=Y[y];
			SBX-=X[y];
			SBY-=Y[y];
		}
		(TS += 2*(2*mo-TA-TB))%=mo;
		A-=area(x,x+1,y);
		B+=area(x,x+1,y+1);
		
		SAX-=X[x];
		SAY-=Y[x];
		TA -= (SAX-(y-x)*X[x])%mo*(Y[x+1]-Y[x])%mo-(SAY-(y-x)*Y[x])%mo*(X[x+1]-X[x])%mo;
		TB += (SBX-(N-y-1)*X[x])%mo*(Y[x+1]-Y[x])%mo-(SBY-(N-y-1)*Y[x])%mo*(X[x+1]-X[x])%mo;
		TA=(mo+TA%mo)%mo;
		TB=(mo+TB%mo)%mo;
	}
	
	cout<<TS<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}