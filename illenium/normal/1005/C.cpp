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

vector <int> vec;
map <int,int> mp;
int n,ans,a[maxn];
bool vis[maxn];

int main()
{
	ll tmp=2;
	while(tmp<=2e9)
	{
		vec.push_back(tmp);
		tmp*=2;
	}
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),mp[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		mp[a[i]]--;
		for(int j=0;j<vec.size();j++)
		{
			if(mp[vec[j]-a[i]])
			{
				vis[i]=1;
				break;
			}
		}
		mp[a[i]]++;
	}
	for(int i=1;i<=n;i++) if(!vis[i]) ans++;
	cout<<ans<<endl;
	return 0;
}