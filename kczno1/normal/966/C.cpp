#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
deque<u64>lk[60];

int main()
{

	int n;
	cin>>n;
	rep(i,1,n)
	{
		u64 x;
		scanf("%lld",&x);
		int j=60;
		while(--j,(x>>j)%2==0);
		lk[j].push_back(x);
	}
	vector<u64>ans;
	u64 now=0;
	rep(tmp,1,n)
	{
		rep(j,0,59)
		if((now>>j)%2==0&&!lk[j].empty())
		{
			u64 x=lk[j].front();lk[j].pop_front();
			ans.push_back(x);
			now^=x;
			break;
		}
	}
	if(ans.size()<n)puts("No");
	else
	{
		puts("Yes");
		for(auto x:ans)printf("%lld ",x);
	}
}