#include <bits/stdc++.h>
using namespace std;


int i,j,t,n,m,del,nmsl;
long double res,a,b,c,d;

void dfs(int a,int b,int c,int t,long double p){
	//printf("%d %d %d %d\n",a,b,c,del);
	//printf("a%Lf\n",p);
	res+=p*t*a/1000000000;
	if(b>0&&c>0){
		dfs(a+min(del/2,b/2),max(nmsl,b-del),c+min(del/2,b/2),t+1,p*b/1000000000);
		dfs(a+min(del/2,c/2),b+min(del/2,c/2),max(nmsl,c-del),t+1,p*c/1000000000);
		return;
	}
	if(b>0){
		dfs(a+min(del,b),max(nmsl,b-del),0,t+1,p*b/1000000000);
		return;
	}
	if(c>0){
		dfs(a+min(del,c),0,max(nmsl,c-del),t+1,p*c/1000000000);
		return;
	}
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%Lf%Lf%Lf%Lf",&c,&b,&a,&d);
		del=d*1000000000;
		res=0;
		dfs(a*1000000000,b*1000000000,c*1000000000,1,1);
		printf("%.20Lf\n",res);
	}
}