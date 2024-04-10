#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int i;
		int mi = 1;
		int ma = 0;
		for (i = N - 1; i > 0; i--)
		{
			if (a == b)
				break;
			mi = min(mi, (int)a[i]-'0');
			ma = max(ma, (int)a[i-1]-'0');
			mi = min(mi, (int)a[i-1] - '0');
			ma = max(ma, (int)a[i] - '0');
			char v = a[i - 1];
			a.pop_back();
			a.pop_back();
			if (mi == 0)
			{
				a.push_back('0');
				if (a == b)
				{
					break;
				}
				a.pop_back();
			}
			if(ma==1)
			{
				a.push_back('1');
				if (a == b)
				{
					break;
				}
				a.pop_back();
			}
			a.push_back(v);
		}
		if (b.size() == 1)
		{
			mi = min(mi, (int)a[i] - '0');
			ma = max(ma, (int)a[i] - '0');
			a.clear();
			if (mi == 0)
			{
				a.push_back('0');
				if (a == b)
				{
					i = 1;
				}
				a.pop_back();
			}
			if (ma == 1)
			{
				a.push_back('1');
				if (a == b)
				{
					i = 1;
				}
				a.pop_back();
			}
		}
		if (i)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}