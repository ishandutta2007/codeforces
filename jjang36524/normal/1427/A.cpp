#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>t;
int arr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M,T;
	cin >> T;
	while (T--)
	{
		t.clear();
		int s = 0;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			t.push_back(a);
			s += a;
		}
		sort(t.begin(), t.end());
		if (s > 0)
		{
			cout << "YES" << '\n';
			int i;
			for (i = N - 1; i >= 0; i--)
			{
				cout << t[i] << ' ';
			}
			cout << '\n';
		}
		else if (s < 0)
		{
			cout << "YES" << '\n';
			int i;
			for (i = N - 1; i >= 0; i--)
			{
				cout << t[N-1-i] << ' ';
			}
			cout << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}