#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
#define mo 1000000009
int qp(int a,int b){
	int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;
}
int main()
{
	int n,w,b;scanf("%d%d%d",&n,&w,&b);
	int ans=w-1;
	for (int i=1;i<=w;i++)ans=1ll*ans*i%mo;
	for (int i=1;i<=b;i++)ans=1ll*ans*i%mo;
	for (int i=w+b-3;i>=w+b-n+1;i--)ans=1ll*ans*i%mo;
	for (int i=1;i<=n-3;i++)ans=1ll*ans*qp(i,mo-2)%mo;
	printf("%d\n",ans);
	return 0;
}