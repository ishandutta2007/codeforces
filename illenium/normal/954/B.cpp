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
#define ull unsigned long long
#define maxn 200005
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

int n,flag;
char ch[maxn];
ull jc[maxn],pre[maxn];

inline ull gethash(int l,int r)
{
    return pre[r]-pre[l-1]*jc[r-l+1];
}

int main()
{
    //sdfgdfgafreopen("CF954B.in","r",stdin);
    n=read(); scanf("%s",ch+1);
    jc[0]=1;
    for(int i=1;i<=n;i++) jc[i]=jc[i-1]*233;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]*233+ch[i];
    for(int i=1;i<=(n/2);i++) if(gethash(1,i)==gethash(i+1,i*2)) flag=i;
    if(flag==0) cout<<n;
    else cout<<n-flag+1;
    return 0;
}