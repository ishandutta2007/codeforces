#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll su[40][100005];
ll mi[40][100005];
int to[40][100005];
int n; ll k;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0;i < n;i++) cin >> to[0][i];
	for (int i = 0;i < n;i++) cin >> mi[0][i], su[0][i] = mi[0][i];
	for (int j = 1;j < 40;j++) for (int i = 0;i < n;i++)
	{
		su[j][i] = su[j-1][i]+su[j-1][to[j-1][i]];
		mi[j][i] = min(mi[j-1][i], mi[j-1][to[j-1][i]]);
		to[j][i] = to[j-1][to[j-1][i]];
	}
	for (int i = 0;i < n;i++)
	{
		ll s = 0, m = 1ll<<62;
		int I = i;
		for (int j = 39;j >= 0;j--) if (k&(1ll<<j))
		{
			s += su[j][I];
			m = min(m, mi[j][I]);
			I = to[j][I];
		}
		cout << s << " " << m << "\n";
	}
	return 0;
}