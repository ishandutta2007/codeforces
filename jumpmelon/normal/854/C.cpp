#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long big;

using namespace std;

const int MAXN = 300000;
int T[MAXN + 10], C[MAXN + 10];
struct cmp
{
	bool operator()(int a, int b)
	{
		return C[a] < C[b];
	}
};
priority_queue<int, vector<int>, cmp> Q;

int main()
{
	int n, k;
	big ans = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &C[i]);
	for(int i = 1; i <= k; i++)
		Q.push(i);
	for(int i = 1; i <= n; i++)
	{
		if(i + k <= n)
			Q.push(i + k);
		int x = Q.top();
		T[x] = i + k;
		Q.pop();
		ans += (big)(T[x] - x) * C[x];
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= n; i++)
		printf("%d ", T[i]);
	printf("\n");
	return 0;
}