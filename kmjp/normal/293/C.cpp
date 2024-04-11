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
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

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

ll N;

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	cin>>N;
	if(N%3) return (void)_P("0\n");
	N/=3;
	
	vector<ll> P;
	for(ll X=1;X*X<=N;X++) if(N%X==0) P.push_back(X);
	
	int ret=0;
	FOR(x,P.size()) for(y=x;y<P.size();y++) {
		if(N/(P[x]*P[y])<P[y]) break;
		if(N%(P[x]*P[y])==0) {
			ll Z=N/(P[x]*P[y]);
			ll a=P[x]+P[y]-Z,b=Z+P[x]-P[y],c=P[y]+Z-P[x];
			if(a>0 && b>0 && c>0 && (a%2==0) && (b%2==0) && (c%2==0)) {
				if(a==b && b==c) ret++;
				else if(a==b || b==c || c==a) ret+=3;
				else ret+=6;
			}
		}
	}
	
	_P("%d\n",ret);
	
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}