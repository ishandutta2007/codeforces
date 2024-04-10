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

vector <ll> vec;
map <ll,ll> mp;

int main()
{
	ll n; cin>>n;
	if(n==1) {puts("1"); return 0;}
	ll fl=0;
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			vec.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n!=1) vec.push_back(n);
	if(vec.size()>1) cout<<1<<endl;
	else cout<<vec[0]<<endl;
	return 0;
}