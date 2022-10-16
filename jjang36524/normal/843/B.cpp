#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
mt19937 gen(2357832);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	int i;
	uniform_int_distribution<int> distribution(0, N-1);
	vector<pair<int, pair<int,int>>>t;
	cout << "? " << M << '\n';
	cout.flush();
	int a, b;
	cin >> a >> b;
	t.push_back({ a,{b,M } });
	for (i = 1; i < 1000; i++)
	{
		int r = distribution(gen) + 1;
		cout <<"? "<< r<<'\n';
		cout.flush();
		int a, b;
		cin >> a >> b;
		t.push_back({ a,{b,r } });
	}
	sort(t.begin(), t.end());
	if (t[0].first >= K)
	{
		cout << "! " << t[0].first << '\n';
		return 0;
	}
	for (i = 0; i < t.size(); i++)
	{
		if (t[i].first> K)
		{
			i--;
			break;
		}
	}
	if (i == t.size())
		i--;
	int curp = t[i].second.second;
	if (t[i].first >= K)
	{
		cout << "! " << t[i].first << '\n';
		cout.flush();
		return 0;

	}
	while (1)
	{
		cout << "? " << curp << '\n';
		cout.flush();
		int a, b;
		cin >> a >> b;
		if (a >= K)
		{
			cout << "! " << a << '\n';
			cout.flush();
			return 0;

		}
		t[i] = { a,{b,b} };
		if (b == -1)
		{
			cout << "! " << -1 << '\n';
			cout.flush();
			return 0;
		}
		curp = b;
	}
}