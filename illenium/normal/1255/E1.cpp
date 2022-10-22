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
#define inf 1e18
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn],n,cnt;
vector <int> vec,tmp;

inline ll jud(int a)
{
	ll tot=0;
	for(int i=0;i<vec.size();i++)
	{
		tmp.push_back(vec[i]);
		if((i+1)%a==0)
		{
			int tmp2=(a+1)/2;
			for(int j=0;j<tmp.size();j++) tot+=abs(tmp[tmp2-1]-tmp[j]);
			tmp.clear();
		}
	}
	return tot;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(); cnt+=a[i];
		if(a[i]==1) vec.push_back(i);
	}
	ll ans=inf;
	for(int i=2;i<=sqrt(cnt);i++)
	{
		if(cnt%i==0)
		{
			ans=min(ans,jud(i));
			ans=min(ans,jud(cnt/i));
			//cout<<i<<" "<<jud(i)<<endl;
		}
	}
	if(cnt!=1) ans=min(ans,jud(cnt));
	//cout<<4<<" "<<jud(4)<<endl;
	if(ans==1e18) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}