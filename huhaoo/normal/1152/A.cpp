/**************************************************************
	File name: 1152A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/4/24 10:37:34
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
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
int a1,b1,a2,b2,n,m;
int main()
{
    n=read();
    m=read();
    fr(i,1,n)
    {
        if(read()%2==0)
            a1++;
        else
            a2++;
    }
    fr(i,1,m)
    {
        if(read()%2==0)
            b1++;
        else
            b2++;
    }
    printf("%d\n",min(a1,b2)+min(a2,b1));
	return 0;
}