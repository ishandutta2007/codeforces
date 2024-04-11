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
int L,R;
int T,B;

int dummy(int x1,int y1,int x2,int y2) {
	int ret=0;
	if(x1<=2&&x2>=2&&y1<=2&&y2>=2) ret++;
	if(x1<=3&&x2>=4&&y1<=3&&y2>=4) ret++;
	_P("%d %d %d %d : %d\n",x1,y1,x2,y2,ret);
	return ret;
}


int ask(int X1,int Y1,int X2,int Y2) {
	//return dummy(X1,Y1,X2-1,Y2-1);
	
	int r;
	printf("? %d %d %d %d\n",X1,Y1,X2-1,Y2-1);
	fflush(stdout);
	scanf("%d",&r);
	return r;
}

pair<pair<int,int>,pair<int,int>> detect(int L,int T,int R,int B) {
	pair<pair<int,int>,pair<int,int>> ret;
	
	//_P("detect %d %d %d %d\n",L,R,T,B);
	
	int L2=L,R2=R;
	while(R2>L2+1) {
		int M=(L2+R2)/2;
		(ask(L,T,M,B)?R2:L2)=M;
	}
	ret.second.first=R=R2;
	//_P("R%d\n",R);
	L2=L;
	while(R2>L2+1) {
		int M=(L2+R2)/2;
		(ask(M,T,R,B)?L2:R2)=M;
	}
	ret.first.first=L=L2;
	//_P("L%d\n",L);
	int T2=T,B2=B;
	while(B2>T2+1) {
		int M=(T2+B2)/2;
		(ask(L,T,R,M)?B2:T2)=M;
	}
	ret.second.second=B=B2;
	T2=T;
	//_P("B%d\n",B);
	while(B2>T2+1) {
		int M=(T2+B2)/2;
		(ask(L,M,R,B)?T2:B2)=M;
	}
	ret.first.second=T2;
	//_P("T%d\n",T);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d",&N);
	L=T=1,R=B=N+1;
	
	while(R>L+1) {
		int M=(L+R)/2;
		x = ask(1,1,M,N+1);
		y = ask(M,1,N+1,N+1);
		if(x==1 && y==1) {
			pair<pair<int,int>,pair<int,int>> p1=detect(1,1,M,N+1);
			pair<pair<int,int>,pair<int,int>> p2=detect(M,1,N+1,N+1);
			return _P("! %d %d %d %d %d %d %d %d\n",
				p1.first.first,p1.first.second,
				p1.second.first-1,p1.second.second-1,
				p2.first.first,p2.first.second,
				p2.second.first-1,p2.second.second-1);
		}
		if(x>=1) R=M;
		else L=M;
	}
	while(B>T+1) {
		int M=(T+B)/2;
		x = ask(1,1,N+1,M);
		y = ask(1,M,N+1,N+1);
		if(x==1 && y==1) {
			pair<pair<int,int>,pair<int,int>> p1=detect(1,1,N+1,M);
			pair<pair<int,int>,pair<int,int>> p2=detect(1,M,N+1,N+1);
			return _P("! %d %d %d %d %d %d %d %d\n",
				p1.first.first,p1.first.second,
				p1.second.first-1,p1.second.second-1,
				p2.first.first,p2.first.second,
				p2.second.first-1,p2.second.second-1);
		}
		if(x>=1) B=M;
		else T=M;
	}
}


int main(int argc,char** argv){
	solve(); return 0;
}