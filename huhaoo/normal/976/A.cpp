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
int n,ans;
char s[210];
int main()
{
	n=read();
	scanf("%s",s+1);
	if(n==1)printf("%s\n",s+1);
	else
	{
		fr(i,1,n)if(s[i]=='0')ans++;
		putchar('1');
		fr(i,1,ans)putchar('0');
		putchar('\n');
	}
	return 0;
}