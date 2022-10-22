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
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
    ll x=0,w=1; char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
    return w==1?x:-x;
}

int n,m,s[maxn],sz[maxn];
int S[maxn],cnt[maxn<<1],p;
ll ans;

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) s[i]=read();
    for(int i=1;i<=n;i++)
    {
    	if(s[i]<m) sz[i]=-1;
    	else if(s[i]>m) sz[i]=1;
    	else sz[i]=0,p=i;
    	S[i]=S[i-1]+sz[i];
	}
	for(int i=0;i<=p-1;i++) ++cnt[S[i]+n+1];
	for(int i=p;i<=n;i++) ans+=cnt[S[i]+n+1]+cnt[S[i]+n];
	cout<<ans;
    return 0;
}