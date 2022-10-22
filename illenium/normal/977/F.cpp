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

int a[maxn],flag,ans;
map <int,int> mp;

int main()
{
    int n;
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
    	mp[a[i]]=max(mp[a[i]],mp[a[i]-1]+1);
    	if(mp[a[i]]>ans)
    	{
    		ans=mp[a[i]];
    		flag=a[i];
		}
	}
	cout<<ans<<endl;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==flag-ans+cnt)
		{
			cnt++;
			printf("%d ",i);
		}
		if(cnt==ans+1) break;
	}
    return 0;
}