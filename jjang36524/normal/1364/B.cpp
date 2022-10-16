#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int T, N, M, a, b, c, d;
int t[100100];
vector<int>p;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		p.clear();
		for (i = 0; i < N; i++)
		{
			cin >> t[i];
		}
		p.push_back(t[0]);
		for (i = 1; i < N - 1; i++)
		{
			if ((t[i - 1] < t[i]) == (t[i] > t[i + 1]))
				p.push_back(t[i]);
		}
		p.push_back(t[N - 1]);
		cout <<'\n'<< p.size() << '\n';
		for (i = 0; i < p.size(); i++)
		{
			cout << p[i] << ' ';
		}
	}
}