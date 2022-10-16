#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int T, N;
set<int>t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		t.clear();
		cin >> N;
		vector<int>a;
		int i;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
			int j;
			for (j = 0; j < i; j++)
			{
				t.insert(a[i] - a[j]);
			}
		}
		cout << t.size() << '\n';

	}
}