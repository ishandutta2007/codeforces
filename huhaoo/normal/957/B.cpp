#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
int n,m;
char s[100][100];
int h[100],l[100];
int main()
{
	n=read();
	m=read();
	fr(i,1,n)
		scanf("%s",s[i]+1);
	fr(i,1,n)
		if(!h[i])
		{
			h[i]=1;
			fr(j,i+1,n)
			{
				int f=1;
				fr(k,1,m)if(s[i][k]!=s[j][k])f=0;
				if(f)h[j]=1;
			}
			fr(j,1,m)if(s[i][j]=='#')
			{
				if(l[j])
				{
					printf("No\n");
					return 0;
				}
				l[j]=1;
			}
		}
	printf("Yes\n");
	return 0;
}