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

int H,W,Q;
int T,Y1,X1,Y2,X2;

template<class V,int MA> class BIT_2d {
public:
	V val[1<<MA][1<<MA];
	BIT_2d(){ZERO(val);};
	V total(int x,int y) {
		V s=0;
		for(int i=x+1;i>0;i-=i&-i) for(int j=y+1;j>0;j-=j&-j) s^=val[i-1][j-1];
		return s;
	}
	void update(int x,int y,V v) {
		for(int i=x+1;i<=1<<MA;i+=i&-i) for(int j=y+1;j<=1<<MA;j+=j&-j) val[i-1][j-1]^=v;
	}
};
BIT_2d<int,13> bit;
int dat[2600][2600];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	scanf("%d%d%d",&H,&W,&Q);
	FOR(i,Q) {
		scanf("%d%d%d%d%d",&T,&Y1,&X1,&Y2,&X2);
		if(T==1) {
			dat[Y1][X1]= r = (rand()<<16)+i;
			bit.update(Y1,X1,r);
			bit.update(Y1,X2+1,r);
			bit.update(Y2+1,X1,r);
			bit.update(Y2+1,X2+1,r);
		}
		if(T==2) {
			r = dat[Y1][X1];
			bit.update(Y1,X1,r);
			bit.update(Y1,X2+1,r);
			bit.update(Y2+1,X1,r);
			bit.update(Y2+1,X2+1,r);
		}
		if(T==3) {
			if(bit.total(Y1,X1)!=bit.total(Y2,X2)) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}