#include <bits/stdc++.h>
const int maxN = 2e5 + 3;
typedef long long ll;
typedef ll llvec[maxN];

int N;
llvec nums,sums;
std::set<ll> sum_exists;
int main()
{
	std::scanf("%d",&N);
	sums[0] = 0;
	for (int i=1;i<=N;++i)
	{
		std::scanf("%I64d",nums+i);
		sums[i] = sums[i-1] + nums[i];
		sum_exists.emplace(sums[i]);
	}
	ll ans = 0;
	for (int i=1;i<=N;++i)
	{
		if (sums[i] > sums[N]/2) break;
		ll sum_suf = sums[N] - sums[i];
		if (sum_exists.count(sum_suf)) ans = sums[i];
	}
	std::printf("%I64d\n",ans);
}