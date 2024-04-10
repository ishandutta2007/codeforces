#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[501];
int nex[501];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		set<pair<int, int>>t;
		int i;
		memset(nex, 0, sizeof(nex));
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
			auto p = t.lower_bound(make_pair(a, 0LL));
			if (p != t.end() && p->first == a)
			{
				nex[p->second] = i;
				t.erase(p);
			}
			else
			{
				t.insert({ a,i });
			}
		}
		if (t.size())
		{
			cout << -1 << '\n';
			continue;
		}
		vector<pair<int,int>>q;
		vector<int>d;
		int c = 0;
		for (i = 0; i < N; i+=2)
		{
			int n = nex[i];
			d.push_back((n-i) * 2);
			d.push_back((n-i) * 2 + 2);
			d.push_back(2);
			int j;
			for(j=i;j<n;j++)
			{
				q.push_back({ c + n - i + j - i,arr[j] });
			}
			for (j = 0;; j++)
			{
				if (i + j > n-1 - j)
					break;
				swap(arr[i+j], arr[n-1 - j]);
			}
			c += (n - i) * 2;
			for (j = i; j <= n; j++)
			{
				q.push_back({ c + n - i + j - i+1,arr[j] });
			}
			for (j = 0;; j++)
			{
				if (i + j > n - j)
					break;
				swap(arr[i + j], arr[n - j]);
			}
			c += (n - i) * 2 + 4;
			memset(nex, 0, sizeof(nex));
			for (j = i + 2; j < N; j++)
			{
				auto p = t.lower_bound(make_pair(arr[j], 0LL));
				if (p != t.end() && p->first == arr[j])
				{
					nex[p->second] = j;
					t.erase(p);
				}
				else
				{
					t.insert({ arr[j],j });
				}
			}
		}
		cout << q.size() << '\n';
		for (i = 0; i < q.size(); i++)
		{
			cout << q[i].first << ' ' << q[i].second << '\n';
		}
		cout << d.size() << '\n';
		for (i = 0; i < d.size(); i++)
			cout << d[i] << ' ';
		cout << '\n';
	}
}