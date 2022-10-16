#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define int long long
using namespace std;
int N;
vector<pair<int, int>>t;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	if (N % 2)
	{
		cout << "NO";
		return 0;
	}
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		t.push_back({ a,b });
	}
	for (i = 1; i < N/2; i++)
	{
		if (t[0].first + t[N / 2].first != t[i].first + t[i + N / 2].first)
		{
			cout << "NO";
			return 0;

		}
		if (t[0].second + t[N / 2].second != t[i].second + t[i + N / 2].second)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}