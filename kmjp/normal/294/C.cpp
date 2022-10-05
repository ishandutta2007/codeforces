#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)
#define _CO(x) { cout << x << endl;}
#define _CI(x) { cin >> x;}

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M;
vector<int> P;

ll mo=1000000007;
ll addmod(ll& l,ll r){ return l=(((l+r)%mo)+mo)%mo;}

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	return C_[P_][Q_];
}

void solve() {
	int f,r,i,j,k,l,x,y,cur,tar;
	
	N=GETi();
	M=GETi();
	FOR(i,M) P.push_back(GETi()-1);
	sort(P.begin(),P.end());
	
	ll res=1;
	res = (comb(N-M,P[0]) * comb(N-M-P[0],N-P[P.size()-1]-1)) % mo;
	M+=P[0]+(N-P[P.size()-1]-1);
	
	FOR(i,P.size()-1) {
		if(P[i+1]-P[i]>1) {
			res = (res * comb(N-M,P[i+1]-P[i]-1)) % mo;
			M+=P[i+1]-P[i]-1;
			FOR(j,P[i+1]-P[i]-2) res = (res*2)%mo;
		}
	}
	
	_P("%lld\n", res);
	
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}