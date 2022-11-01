#include <cstdio>
#include <queue>

using namespace std;

queue<int> q;
int t[4096];
char x[4096];
int ans;
int n;

int main()
{
	scanf("%d%s", &n, x);
	for (int i = 0;i < n;i++)
	{
		t[i] = -1;
		if (x[i] != '.')
		{
			t[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		int next = u;
		int sup;
		if (x[u] == 'L')
		{
			next--;
			sup = next - 1;
		} else
		{
			next++;
			sup = next + 1;
		}
		if (next < 0 || next >= n)
			continue;
		if (x[next] != '.')
			continue;
		if (sup < 0 || sup >= n)
		{
			x[next] = x[u];
			t[next] = t[u] + 1;
			q.push(next);
			continue;
		}
		if (t[sup] == t[u])
			continue;
		x[next] = x[u];
		t[next] = t[u] + 1;
		q.push(next);
	}
	for (int i = 0;i < n;i++) if (x[i] == '.')
		ans++;
	printf("%d\n", ans);
	return 0;
}