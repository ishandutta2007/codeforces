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

ll n;

int main()
{
	cin>>n;
	ll base=1,ans=0;
	while(n>1)
	{
		ans+=(n>>1)*base;
		base=base<<1;
		n-=n>>1;
	}
	cout<<ans;
	return 0;
}