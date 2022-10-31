#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;
int k,x,y,m,n;
char s[1234532];

struct scob{
	int a,b,c;
	scob(){
		a = 0;
		b = 0;
		c = 0;
	}
	scob(int x, int y, int z) {
		a=x;
		b=y;
		c=z;
	}
	scob operator + (scob x){
		int q=min(b,x.c);
		return scob(a+x.a+q*2, b+x.b-q, c+x.c-q);
	}
} t[4000000];

void build(int v, int tl, int tr){
	if (tl==tr){
		if (s[tl]=='(') t[v]=scob(0,1,0); else 
		t[v]=scob(0,0,1);
	} else {
		int tm=(tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
	    t[v]=t[v*2]+t[v*2+1];
	}
}

scob sum(int v, int tl, int tr , int x, int y){
	if (tl>y || tr<x) return scob(0,0,0);
	if (tl>=x && tr<=y) return t[v];
	int tm=(tl+tr)/2;
	return sum(v*2,tl,tm,x,y)+sum(v*2+1,tm+1,tr,x,y);



}


int main(){
    scanf("%s\n",s+1);
    n=strlen(s+1);
    build(1,1,n);
    scanf("%d",&m);
    for (int i=0; i<m; i++){
    	scanf("%d%d",&x,&y);
        printf("%d\n",sum(1,1,n,x,y).a);
    }

    

	return 0;                        

}