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
#define maxn 300005
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

ll ans,n,mx;
char ch[maxn];
map <int,ll> mp;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		ll flag=0,k=0,len=strlen(ch+1);
		for(int j=1;j<=len;j++)
		{
			if(ch[j]=='(') k++;
			else k--;
			flag=min(flag,k);
		}
		if(flag<0&&k>flag) continue;
		else
		{
			mp[k]++;
			mx=max(mx,mp[k]);
		}
	}
	for(int i=0;i<=maxn;i++) ans+=mp[i]*mp[-i];
	cout<<ans<<endl;
	return 0;
}