#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int askl(int x,int y){
	x=x-y;
	if(x<1) x+=n;
	return x;
}
int askr(int x,int y){
	x=x+y;
	if(x>n) x-=n;
	return x;
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&k);m=sqrt(n);
	int tt=0,x=0,y,a,b;
	while(1){
		x=rand()*rand()%n+1;
		printf("? %d\n",x);
		fflush(stdout);
		scanf("%d",&y);
		++tt;
		if(y!=k) break;
	}
	while(tt<m){
		a=rand()%n+1;
		printf("? %d\n",a);
		fflush(stdout);
		scanf("%d",&b);
		++tt;
	}
	if(y>k){
		a=x;b=y;
		do{
			a=askl(a,m);
			printf("? %d\n",a);
			fflush(stdout);
			scanf("%d",&b);
		}while(b>=k);
	}
	else{
		a=x;b=y;
		do{
			a=askr(a,m);
			printf("? %d\n",a);
			fflush(stdout);
			scanf("%d",&b);
		}while(b<=k);
		swap(a,x);
		swap(b,y);
	}
	int lim;
	if(x>a) lim=x-a-1;
	else lim=n-a+x-1;
	int l=1,r=lim,mid;
	while(l!=r){
		mid=(l+r)>>1;
		x=askr(a,mid);
		printf("? %d\n",x);
		fflush(stdout);
		scanf("%d",&y);
		if(y>=k) r=mid;
		else l=mid+1;
	}
	x=askr(a,l);
	printf("! %d\n",x);
	return 0;
}