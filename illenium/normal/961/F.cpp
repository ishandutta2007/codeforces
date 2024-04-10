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
#define maxn 1000005
#define re register
#define inf 1e9
#define eps 1e-10
#define mod 1000000007
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

string s;
ull pre[maxn],h[maxn];
int ans[maxn],cnt,n,len,l,r;

inline ull gethash(int l,int r)
{
	return (h[r]-(h[l-1]*pre[r-l+1])%mod+mod)%mod;
}

int main()
{
	cin>>n; cin>>s; s=" "+s; pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=(pre[i-1]*233)%mod;
	for(int i=1;i<=n;i++) h[i]=(h[i-1]*233+s[i])%mod;
	if(n%2==1) l=n/2+1,r=n/2+1;
	else l=n/2,r=n/2+1;
	len=1;
	while(r<=n)
	{
		len+=2;
		while(len!=-1&&(gethash(l,l+len-1)!=gethash(r-len+1,r)||len>=r-l+1)) len-=2;
		ans[++cnt]=len;
		--l; ++r;
	}
	for(int i=cnt;i;i--) printf("%d ",ans[i]);
	return 0;
}