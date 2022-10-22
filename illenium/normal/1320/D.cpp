#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

ll h[maxn][2],p[maxn],cnt[maxn];
const ll mod=998244353;
char s[maxn];

inline ll q(int l,int r)
{
	if(l&1) return (h[r][0]-h[l-1][0]*p[cnt[r]-cnt[l-1]]%mod+mod)%mod;
	else return (h[r][1]-h[l-1][1]*p[cnt[r]-cnt[l-1]]%mod+mod)%mod;
}

int main()
{
	int n; cin>>n; scanf("%s",s+1); p[0]=1;
	for(int i=1;i<=n;i++) p[i]=(p[i-1]*233)%mod;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			cnt[i]=cnt[i-1]+1;
			h[i][0]=(h[i-1][0]*233+(i&1)+1)%mod;
			h[i][1]=(h[i-1][1]*233+((i&1)^1)+1)%mod;
		}
		else h[i][0]=h[i-1][0],h[i][1]=h[i-1][1],cnt[i]=cnt[i-1];
	}
	int Q=read();
	while(Q--)
	{
		int l1=read(),l2=read(),k=read();
		if(q(l1,l1+k-1)==q(l2,l2+k-1)) puts("Yes");
		else puts("No");
	}
	return 0;
}