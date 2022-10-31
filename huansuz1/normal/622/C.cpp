#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define mp make_pair
#define ll long long
using namespace std;
ll a[223456],n,ch;
int k,x,y;
pair< int ,int > t[1412345],t1[1431256];


void build(int v, int tl, int tr){
	if (tl==tr) { t[v]=mp(a[tl],tl); t1[v]=mp(a[tl],tl); } else {
		int tm=(tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		t[v]=max(t[v*2],t[v*2+1]);
		t1[v]=min(t1[v*2],t1[v*2+1]);
	}
}

pair<int , int> maks(int v, int tl, int tr, int x, int y){
	if (tl>y || tr<x) return mp(-1000009,-1); 
	if(x<=tl && tr<=y) return t[v];
	int tm=(tl+tr)/2;
	return max(maks(v*2,tl,tm,x,y),maks(v*2+1,tm+1,tr,x,y));
}


pair<int , int> mins(int v, int tl, int tr, int x, int y){
	if (tl>y || tr<x) return mp(1000009,-1); 
	if(x<=tl && tr<=y) return t1[v];
	int tm=(tl+tr)/2;
	return min(mins(v*2,tl,tm,x,y),mins(v*2+1,tm+1,tr,x,y));
}




int main(){
	scanf("%d%d",&n,&k);

	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	build(1,1,n);	
	for(int i=0; i<k; i++) {
	    scanf("%d%d%d",&x,&y,&ch);
	    pair<int , int > p1=maks(1,1,n,x,y);
	    pair<int , int > p2=mins(1,1,n,x,y);


	    if (p1.first!=ch ) printf("%d\n",p1.second); else
	    if (p2.first!=ch ) printf("%d\n",p2.second); else
	    printf("%d\n",-1);
	}



	return 0;

}