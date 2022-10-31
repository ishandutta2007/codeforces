#include <bits/stdc++.h>
using namespace std;

int i,j,k,l,r,md,t,n,res[2050],m,tmp;

int ask(int a,int b){
	printf("? %d %d\n",a,1);
	for(int i=1;i<=a;i++){
		printf("%d ",i);
	}
	printf("\n%d\n",b);
	fflush(stdout);
	scanf("%d",&a);return a;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		l=1;r=0;m=n-1;tmp=0;
		memset(res,0,sizeof(res));
		for(i=1;i<n;i++){
			if(!r){if(ask(i,i+1)){r=i;k=i+1;res[i+1]=1;m--;}}
			else{if(ask(r,i+1)){res[i+1]=1;m--;}}
		}
		while(l<=r){
			md=(l+r)>>1;
			if(ask(md,k)){tmp=md;r=md-1;}
			else{l=md+1;}
		}
		res[tmp]=1;
		printf("! %d ",m);
		for(i=1;i<=n;i++){
			if(!res[i]){printf("%d ",i);}
		}puts("");
		fflush(stdout);
	}
}