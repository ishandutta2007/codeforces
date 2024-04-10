#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
int t,n,i,x,r[3],c[3],u,v;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=x=0;i<3;i++)
		{
			scanf("%d%d",r+i,c+i);
			x^=r[i]^c[i];
		}
		scanf("%d%d",&u,&v);
		x&=1;
		for(i=0;i<3;i++)if(!((r[i]^c[i]^x)&1))break;
		if((r[i]==1||r[i]==n)&&(c[i]==1||c[i]==n))if(u==r[i]||v==c[i])puts("YES");
		else puts("NO");
		else if((u^v^x)&1)puts("YES");
		else if(!((u^r[i])&1)&&!((v^c[i])&1))puts("YES");
		else puts("NO");
	}
	return 0;
}