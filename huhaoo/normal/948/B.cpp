#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define fr(i,a,b) for(int i=a,_end_=b;i<=_end_;i++)
#define fd(i,a,b) for(int i=a,_end_=b;i>=_end_;i--)
using namespace std;
int read(){
	int s=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		k=c=='-'?-1:1;
		c=getchar();
	}		
	while(c>='0'&&c<='9'){
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return s*k;
}
#define N 1000010
int n=read(),c[N],p[N],m,pre[N],calc[N];
int main()
{
	fr(i,2,n)
	{
		if(!c[i])
		{
			p[++m]=i;
			pre[i]=i;
		}
		fr(j,1,m)
			if(i*p[j]>N)break;
			else if(i%p[j])
			{
				c[i*p[j]]=1;
				pre[i*p[j]]=p[j];
			}
			else
			{
				c[i*p[j]]=1;
				pre[i*p[j]]=p[j];
				break;
			}
	}
	calc[1]=1;
	fr(i,2,n)calc[i]=max(calc[i/pre[i]],pre[i]);
	fr(i,2,n)if(!c[i])calc[i]=1;
	int ans=1000000000;
	fr(i,n-calc[n]+1,n)ans=min(ans,i-calc[i]+1);
	printf("%d\n",ans);
	return 0;
}