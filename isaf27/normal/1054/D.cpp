#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

ll gett(int k)
{
	return ((ll)k * (ll)(k - 1)) / 2LL;
}

int main()
{
	cin.sync_with_stdio(0); 
	cin >> n >> k;
	int a = 0;
	ll ans = 0;
	map<int, int> kol;
	kol[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		a ^= min(b, (1 << k) - 1 - b);
		kol[a]++;
	}		
	for (pair<int, int> t : kol)
	{
		ans += gett(t.second / 2);
		ans += gett((t.second + 1) / 2);	
	}
	cout << gett(n + 1) - ans;
	return 0;
}