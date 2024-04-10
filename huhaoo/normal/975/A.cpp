#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 1010
int n,a[N][50],p[N],ans;
char s[N];
int main()
{
	n=read();
	fr(i,1,n)
	{
		scanf("%s",s+1);
		fr(j,1,strlen(s+1))a[i][s[j]-'a']=1;
		p[i]=1;
	}
	fr(i,1,n-1)
		if(p[i])
			fr(j,i+1,n)
			{
				int f=1;
				fr(k,0,25)if(a[i][k]^a[j][k])
				{
					f=0;
					break;
				}
				if(f)p[j]=0;
			}
	fr(i,1,n)ans+=p[i];
	printf("%d\n",ans);
	return 0;
}