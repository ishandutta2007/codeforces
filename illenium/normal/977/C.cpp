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

ll n,k,a[maxn];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(k==0)
	{
		if(a[1]==1) puts("-1");
		else printf("%lld",a[1]-1);
		return 0;
	}
	if(a[k]==a[k+1]) puts("-1");
	else printf("%d",a[k]);
	return 0;
}