#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;

inline int read()
{
    int x=0,w=1; char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
    while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
    return w==1?x:-x;
}

int n,a[5005];

int main()
{
    bool flag=false;
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
        if(a[a[a[i]]]==i) {flag=1; break;}
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}