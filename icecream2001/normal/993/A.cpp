#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=1e9;
struct P{
	int x,y;
}a[4],b[4];
int X,Y;
int u,d,l,r;
int U,D,L,R;
bool check(int x,int y){
	if(x<u||x>d||y<l||y>r) return 0;
	X=y-x;Y=y+x;
	if(X<U||X>D||Y<L||Y>R) return 0;
	return 1;
}
int main(){
	u=U=l=L=inf;
	d=D=r=R=-inf;
	for(int i=0;i<4;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		u=min(u,a[i].x);d=max(d,a[i].x);
		l=min(l,a[i].y);r=max(r,a[i].y);
	}
	for(int i=0;i<4;++i){
		scanf("%d%d",&b[i].x,&b[i].y);
		X=b[i].y-b[i].x;Y=b[i].y+b[i].x;
		U=min(U,X);D=max(D,X);
		L=min(L,Y);R=max(R,Y);
	}
	for(int i=-101;i<=101;++i){
		for(int j=-101;j<=101;++j){
			if(check(i,j)){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
	
}