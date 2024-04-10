#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > solution;
pair<pair<int, int>, int> booking[1001];
int cache[1001][1001];
int move[1001][1001];
pair<int, int> table[1001];
int n;
int t;

int dp(int b, int seat)
{
	if (seat == t)
		return 0;
	if (b == n)
		return 0;
	if (booking[b].first.first > table[seat].first)
		return (cache[b][seat] = dp(b, seat+1));
	if (cache[b][seat] != -1)
		return cache[b][seat];
	int alt1 = dp(b+1, seat+1)+booking[b].first.second;
	int alt2 = dp(b+1, seat);
	if (alt1 > alt2)
	{
		move[b][seat] = 1;
		return (cache[b][seat] = alt1);
	}
	return (cache[b][seat] = alt2);
}

int backtrack(int b, int seat)
{
	if (seat == t || b == n)
		return 0;
	if (booking[b].first.first > table[seat].first)
		return backtrack(b, seat+1);
	if (move[b][seat])
	{
		solution.push_back(make_pair(booking[b].second, table[seat].second));
		return (backtrack(b+1, seat+1) + 1);
	}
	return backtrack(b+1, seat);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d", &booking[i].first.first, &booking[i].first.second);
		booking[i].second = i + 1;
	}
	scanf("%d", &t);
	for (int i = 0;i < t;i++)
	{
		scanf("%d", &table[i].first);
		table[i].second = i + 1;
	}
	sort(booking, booking+n);
	sort(table, table+t);
	for (int i = 0;i < n;i++) for (int j = 0;j < t;j++)
		cache[i][j] = -1;
	int ans = dp(0, 0);
	printf("%d %d\n", backtrack(0, 0), ans);
	for (int i = 0;i < solution.size();i++)
		printf("%d %d\n", solution[i].first, solution[i].second);
	return 0;
}