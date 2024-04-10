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

int X,Y;
int RX[667],RY[667];
int Ys[1010],Xs[1010];

void check() {
	if(Xs[X-1]) {
		cout<<X-1<<" "<<Y<<endl;
		exit(0);
	}
	if(Xs[X+1]) {
		cout<<X+1<<" "<<Y<<endl;
		exit(0);
	}
	if(Ys[Y-1]) {
		cout<<X<<" "<<Y-1<<endl;
		exit(0);
	}
	if(Ys[Y+1]) {
		cout<<X<<" "<<Y+1<<endl;
		exit(0);
	}
}

void check2() {
	int i,x,y;
	cin>>i>>x>>y;
	if(i==-1) exit(0);
	i--;
	Xs[RX[i]]--;
	Ys[RY[i]]--;
	RX[i]=x;
	RY[i]=y;
	Xs[RX[i]]++;
	Ys[RY[i]]++;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	FOR(i,666) {
		cin>>RX[i]>>RY[i];
		Xs[RX[i]]++;
		Ys[RY[i]]++;
	}
	while(X!=500 || Y!=500) {
		int dx=0,dy=0;
		
		check();
		if(X>500) dx=-1;
		if(X<500) dx=1;
		if(Y>500) dy=-1;
		if(Y<500) dy=1;
		X+=dx;
		Y+=dy;
		cout<<X<<" "<<Y<<endl;
		check2();
	}
	
	int C[2][2]={};
	FOR(i,666) C[RX[i]>500][RY[i]>500]++;
	int dx,dy;
	if(C[0][0]<=666-499) dx=dy=1;
	if(C[0][1]<=666-499) dx=1, dy=-1;
	if(C[1][0]<=666-499) dx=-1, dy=1;
	if(C[1][1]<=666-499) dx=dy=-1;
	
	while(1) {
		check();
		X+=dx;
		Y+=dy;
		cout<<X<<" "<<Y<<endl;
		check2();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}