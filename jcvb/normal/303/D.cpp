#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int pr(int x){
	for (int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
int f[1000];
int tot=0;
int qp(int a,int b,int mo){
	int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;
}
int test(int g,int p){
	for (int i=1;i<tot;i++)if(qp(g,f[i],p)==1)return 0;
	return 1;
}
int main()
{
	int n,x;
	int p;
	scanf("%d%d",&n,&x);p=n+1;
	int ma=-1;
	if(!pr(n+1))printf("-1\n");
	else{	
		for (int i=1;i*i<=n;i++)if(n%i==0){
			f[++tot]=i;
			f[++tot]=n/i;
			if(i*i==n)--tot;
		}
		sort(f+1,f+1+tot);
		int g;
		for (g=x-1;g>=2;g--)if(test(g,p))break;
		if(g==1)printf("-1\n");
		else printf("%d\n",g);
	}
	return 0;
}