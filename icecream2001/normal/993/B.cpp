#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=1e9;
struct P{
	int x,y;
}a[20],b[20];
int n,m,ans1=0,ans2=0;
int check(int i,int j){
	if(a[i].x==b[j].x&&a[i].y==b[j].y) return 0;
	if(a[i].x==b[j].x||a[i].x==b[j].y)return a[i].x;
	if(a[i].y==b[j].x||a[i].y==b[j].y) return a[i].y;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&b[i].x,&b[i].y);
		if(b[i].x>b[i].y) swap(b[i].x,b[i].y);
	}
	bool flag1=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!check(i,j)) continue;
			if(ans1==0||ans1==check(i,j)) ans1=check(i,j);
			else flag1=1;
		}
	}
	if(ans1&&flag1==0){
		printf("%d\n",ans1);return 0;
	}
	if(ans1==0){
		printf("-1\n");return 0;
	}
	flag1=0;
	for(int i=1;i<=n;++i){
		ans1=0;
		for(int j=1;j<=m;++j){
			if(!check(i,j)) continue;
			if(ans1==0||ans1==check(i,j)) ans1=check(i,j);
			else flag1=1;
		}
	}
	for(int j=1;j<=m;++j){
		ans1=0;
		for(int i=1;i<=n;++i){
			if(!check(i,j)) continue;
			if(ans1==0||ans1==check(i,j)) ans1=check(i,j);
			else flag1=1;
		}
	}
	if(flag1){
		printf("-1\n");return 0;
	}
	printf("0\n");
	return 0;
}