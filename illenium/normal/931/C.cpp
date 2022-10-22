#include<cstdio>
#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define N 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[N];

int main()
{
	int n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    if(a[n]-a[1]<=1) 
    {
        printf("%d\n",n);
        for(int i=1;i<=n;++i) printf("%d ",a[i]);
        return 0;
    }
    int s1=0,s2=0,s3=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==a[1]) s1++;
        else if(a[i]==a[n]) s3++;
        else s2++;
    }
    int t=min(s1,s3),k=s2/2;
    int m=a[1];
    if(t>k)
    {
        for(int i=1;i<=t;++i) a[i]=m+1;
        for(int i=1;i<=t;++i) a[n-i+1]=m+1;
        printf("%d\n",n-t*2);
        for(int i=1;i<=n;++i) printf("%d ",a[i]);
    }
    else
    {
        for(int i=1;i<=k;++i) a[s1+i*2-1]=m,a[s1+i*2]=m+2;
        printf("%d\n",n-k*2);
        for(int i=1;i<=n;++i) printf("%d ",a[i]);
    }
}