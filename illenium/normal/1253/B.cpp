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
#define maxn 1000005
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

int a[maxn],cnt[maxn],cnt2;
map <int,int> mp;
vector <int> ans;

int main()
{
	int n=read(); ans.push_back(0);
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			a[i]=abs(a[i]);
			if(cnt[a[i]]==1) cnt[a[i]]--,mp[a[i]]=1,cnt2--;
			else {puts("-1"); return 0;}
			if(cnt2==0)
			{
				ans.push_back(i);
				mp.clear();
			}
		}
		else
		{
			if(cnt[a[i]]==1) {puts("-1"); return 0;}
			else if(mp[a[i]]==0) cnt[a[i]]++,cnt2++,mp[a[i]]=1;
		}
	}
	if(cnt2!=0) {puts("-1"); return 0;}
	//ans.push_back(n);
	cout<<ans.size()-1<<endl;
	for(int i=1;i<ans.size();i++) printf("%d ",ans[i]-ans[i-1]);
	return 0;
}