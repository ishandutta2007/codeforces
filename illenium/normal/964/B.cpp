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

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,A,B,C,T,a[1005],ans;

int main()
{
    scanf("%d%d%d%d%d",&n,&A,&B,&C,&T);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ans=n*A;
    if(B<C) for(int i=1;i<=n;i++) ans+=(C-B)*(T-a[i]);
    printf("%d\n",ans);
    return 0;
}