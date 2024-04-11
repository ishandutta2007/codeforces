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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
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

int N;
vector<pair<int,int> > V;
vector<int> XX,YY;

void uniq(vector<int>& DD) {
	vector<int> VV=DD;
	sort(VV.begin(),VV.end());
	VV.erase(unique(VV.begin(),VV.end()),VV.end());
	int i,j,k;
	FOR(i,DD.size()) {
		k=DD[i];
		FOR(j,VV.size()) if(k==VV[j]) DD[i]=j+1;
	}
}

void solve() {
	int f,r,i,j,k,l, x,y;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y>>j>>k;
		XX.push_back(x);
		YY.push_back(y);
		XX.push_back(j);
		YY.push_back(k);
	}
	int lx=*min_element(XX.begin(),XX.end());
	int ly=*min_element(YY.begin(),YY.end());
	int rx=*max_element(XX.begin(),XX.end());
	int ry=*max_element(YY.begin(),YY.end());
	
	if(rx-lx!=ry-ly) return (void)_P("NO\n");
	
	uniq(XX);
	uniq(YY);
	
	lx=*min_element(XX.begin(),XX.end());
	ly=*min_element(YY.begin(),YY.end());
	rx=*max_element(XX.begin(),XX.end());
	ry=*max_element(YY.begin(),YY.end());
	
	for(y=ly;y<ry;y++) {
		for(x=lx;x<rx;x++) {
			int jj=0;
			FOR(i,N) {
				if(XX[i*2]<=x && x<XX[i*2+1] && YY[i*2]<=y && y<YY[i*2+1]) jj=1;
			}
			if(jj==0) return (void)_P("NO\n");
		}
	}
	
	_P("YES\n");
	
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}