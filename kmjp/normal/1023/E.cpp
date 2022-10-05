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

int ask(int Y1,int X1,int Y2,int X2) {
	assert(abs(Y2-Y1)+abs(X2-X1)>=N-1);
	cout<<"? "<<Y1<<" "<<X1<<" "<<Y2<<" "<<X2<<endl;
	cout.flush();
	string S;
	cin>>S;
	return S=="YES";
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	string ret,ret2;
	x=1,y=1;
	while(x+y<N+1) {
		if(ask(y+1,x,N,N)) {
			y++;
			ret+="D";
		}
		else {
			x++;
			ret+="R";
		}
	}
	x=y=N;
	while(x+y>N+1) {
		if(ask(1,1,y,x-1)) {
			x--;
			ret2+="R";
		}
		else {
			y--;
			ret2+="D";
		}
	}
	reverse(ALL(ret2));
	cout<<"! "<<(ret+ret2)<<endl;
	
}


int main(int argc,char** argv){
	solve(); return 0;
}