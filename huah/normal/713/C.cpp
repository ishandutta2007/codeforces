#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e3+5,mod=998244353;
const ll inf=1e18;
int n;
priority_queue<int>q;
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		x-=i;
		q.push(x);
		if(q.top()>x)
		{
			ans+=q.top()-x;
			q.pop();
			q.push(x);
		}
	}
    printf("%lld\n",ans);
}