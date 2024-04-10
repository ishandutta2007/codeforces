#include <cstdio>
#include <algorithm>

using namespace std;

struct obj
{
	int in;
	int out;
	int w;
	int s;
	int v;
	bool operator< (const obj& other) const
	{
		if (in != other.in)
			return (in < other.in);
		return (out > other.out);
	};
};

int cache[501][1001];
int dp[1001];
obj parc[1001];
int n;
int S;

int main()
{
	scanf("%d%d", &n, &S);
	for (int i = 0;i < n;i++)
		scanf("%d%d%d%d%d", &parc[i].in, &parc[i].out, &parc[i].w, &parc[i].s, &parc[i].v);
	sort(parc, parc+n);
	for (int upto = n-1;upto >= 0;upto--) for (int canhold = 0;canhold <= S;canhold++)
	{
		for (int i = 0;i < 1001;i++)
			dp[i] = 0;
		for (int i = n-1;i > upto;i--)
		{
			if (parc[i].in >= parc[upto].in &&
			  parc[i].out <= parc[upto].out && canhold-parc[i].w >= 0)
			{
				dp[parc[i].in] = max(dp[parc[i].in],
				  dp[parc[i].out]+parc[i].v+cache[i][min(parc[i].s, canhold-parc[i].w)]);
			}
			for (int j = parc[i].in-1;j >= parc[i-1].in;j--)
				dp[j] = max(dp[j], dp[j+1]);
		}
		cache[upto][canhold] = -1;
		for (int i = 1001;i >= 0;i--)
			cache[upto][canhold] = max(cache[upto][canhold], dp[i]);
	}
	for (int i = 0;i < 1001;i++)
		dp[i] = 0;
	for (int i = n-1;i >= 0;i--)
	{
		if (S-parc[i].w >= 0)
		{
			dp[parc[i].in] = max(dp[parc[i].in],
			  dp[parc[i].out]+parc[i].v+cache[i][min(parc[i].s, S-parc[i].w)]);
		}
		for (int j = parc[i].in-1;j >= 0;j--)
			dp[j] = max(dp[j], dp[j+1]);
	}
	int ans = 0;
	for (int i = 0;i < 1001;i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}