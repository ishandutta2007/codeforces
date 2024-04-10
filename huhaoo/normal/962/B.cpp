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
#define N 200010
int n,a,b,ans,l;
char s[N];
void printa(int x)
{
	ans+=min(a,x);
	a-=min(a,x);
}
void printb(int x)
{
	ans+=min(b,x);
	b-=min(b,x);
}
int main()
{
	n=read();
	a=read();
	b=read();
	scanf("%s",s+1);
	fr(i,1,n)
		if(s[i]=='.')
		{
			while(s[i]=='.')
			{
				i++;
				l++;
			}
			if(l&1)
				if(a<b)
				{
					printa(l>>1);
					printb((l>>1)+1);
				}
				else
				{
					printa((l>>1)+1);
					printb(l>>1);
				}
			else
			{
				printa(l>>1);
				printb(l>>1);
			}
			l=0;
		}
	printf("%d\n",ans);
	return 0;
}