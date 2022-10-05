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

ll N;
ll X[3],Y[3];

int ask(ll x,ll y) {
	int ret;
	//cout<<x<<" "<<y<<endl;
	printf("%lld %lld\n",x,y);
	fflush(stdout);
	scanf("%d",&ret);
	//cin>>ret;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%lld",&N);
	X[1]=X[2]=N+1;
	Y[1]=Y[2]=N+1;
	while(1) {
		double SA=(double)(X[1]-X[0])*(double)(Y[1]-Y[0]);
		double SB=(double)(X[1]-X[0])*(double)(Y[2]-Y[1]);
		double SC=(double)(X[2]-X[1])*(double)(Y[1]-Y[0]);
		
		ll TX=(X[0]+X[1])/2;
		ll TY=(Y[0]+Y[1])/2;
		if(SB>SA+SC) TY=Y[1];
		if(SC>SA+SB) TX=X[1];
		r = ask(TX,TY);
		if(r==0) return;
		if(r==1) X[0]=TX+1;
		else if(r==2) Y[0]=TY+1;
		else X[1]=TX, Y[1]=TY;
		if(X[1]<=X[0]) X[1]=X[2], Y[2]=Y[1];
		if(Y[1]<=Y[0]) Y[1]=Y[2], X[2]=X[1];
	} 
}


int main(int argc,char** argv){
solve(); return 0;
}