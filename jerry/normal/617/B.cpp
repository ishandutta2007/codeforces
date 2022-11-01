#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int nut[105];
int n, has;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> nut[i];
		has |= nut[i];
	}
	if (!has) cout << 0 << endl;
	else
	{
		ll ans = 1;
		int pr = 0;
		while (!nut[pr]) pr++;
		for (int i = pr+1;i < n;i++) if (nut[i])
		{
			ans *= (i-pr);
			pr = i;
		}
		cout << ans << endl;
	}
	return 0;
}