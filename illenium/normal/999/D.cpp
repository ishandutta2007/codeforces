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
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,cnt[maxn],arr[maxn],res,val,ans;
set <ll> st;

int main()
{
	n=read(); m=read();
	for(int i=0;i<m;cnt[i++]=n/m) st.insert(i);
	for(int i=0;i<n;i++)
	{
		arr[i]=read(); res=arr[i]%m;
		if(res>*--st.end())  val=*st.begin();
		else val=*st.lower_bound(res);
		ans=(ans)+(val-res+m)%m;
		if(!--cnt[val]) st.erase(val);
		arr[i]=arr[i]+(val-res+m)%m;
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++) printf("%lld ",arr[i]);
	return 0;
}