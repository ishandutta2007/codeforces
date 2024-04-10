#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100],x,y;
int q,i,j,k;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%I64d",&i,&x);
		for(j=1;j<61;j++)if((1LL<<j)>x)break;
		if(i==3)
		{
			for(x=(x+a[j]&((1LL<<j-1)-1))|(1LL<<j-1);x>1;x>>=1,j--)printf("%I64d ",(x-a[j]&((1LL<<j-1)-1))|(1LL<<j-1));
			puts("1");
		}
		else
		{
			scanf("%I64d",&y);
			if(i==1)k=j;
			else k=60;
			for(;j<=k;j++,y<<=1)a[j]=a[j]+y&((1LL<<j-1)-1);
		}
	}
	return 0;
}