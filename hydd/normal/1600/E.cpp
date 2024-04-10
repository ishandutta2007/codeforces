#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;
int n, a[N];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int mx = *max_element(a + 1, a + n + 1);
	if (n == 1)
	{
		puts("Alice");
		return 0;
	}
	if (a[1] == mx || a[n] == mx)
	{
		puts("Alice");
		return 0;
	}
	queue<int> L, R;
	for (int i = 1; i <= n; ++i)
	{
		L.push(a[i]);
		if (a[i] >= a[i + 1]) break;
	}
	for (int i = n; i >= 1; --i)
	{
		R.push(a[i]);
		if (a[i - 1] <= a[i]) break;
	}
//	for (int x : L) printf("%d ", x); putchar('\n');
//	for (int x : R) printf("%d ", x); putchar('\n');
	bool status = true; // true stands for Alice, false = b
	while (!L.empty() || !R.empty())
	{
		if (L.empty() || R.empty())
		{
			int rem = L.size() + R.size();
			puts((status ^ rem) % 2 == 1 ? "Bob" : "Alice");
			return 0;
		}
		int x = L.front(), y = R.front();
		if (x < y)
		{
			if (R.size() % 2 == 1)
			{
				puts(status ? "Alice" : "Bob");
				return 0;
			}
			else
			{
				L.pop();
				status ^= 1;
			}
		}
		else if (x > y)
		{
			if (L.size() % 2 == 1)
			{
				puts(status ? "Alice" : "Bob");
				return 0;
			}
			else
			{
				R.pop();
				status ^= 1;
			}
		}
		else if (x == y)
		{
			if (L.size() % 2 == 1 || R.size() % 2 == 1)
			{
				puts(status ? "Alice" : "Bob");
				return 0;
			}
			else
			{
				puts(!status ? "Alice" : "Bob");
				return 0;
			}
		}
	}
}