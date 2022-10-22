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

ll n,m,k;

int main()
{
	cin>>n>>m>>k;
	if(k<=n-1)
	{
		cout<<k+1<<" 1";
		return 0;
	}
	else
	{
		k-=n;
		if(k<m-1)
		{
			cout<<n<<" "<<2+k;
			return 0;
		}
		k-=(m-1);
		ll p=k/(m-1);
		ll q=k%(m-1);
		if(p%2==0)
		{
			cout<<n-1-p<<" "<<m-q;
			return 0;
		}
		else
		{
			cout<<n-1-p<<" "<<2+q;
			return 0;
		}
	}
	return 0;
}