#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long int ll;

vector<ll> a;
int n, ans = 0;

bool binsearch(ll x)
{
	if(x < 1 || x > a[n - 1])
		return false;

	int l = 0;
	int r = a.size() - 1;

	while(r - l > 1)
	{
		int m = (l + r) / 2;

		if(x < a[m])
			r = m;
		else if(x > a[m])
			l = m;
		else
			return m;
	}

	return a[l] == x || a[r] == x;
}

bool needrem(int i)
{
	ll x = a[i];

	for(ll j = 1; j <= 2000000000; j <<= 1)
	{
		if(x == j - x)
		{
			if(i == 0 && a[i + 1] == x)
				return false;

			if(i == n - 1 && a[i - 1] == x)
				return false;

			if(a[i - 1] == x || a[i + 1] == x)
				return false;
		}
		else if(binsearch(j - x))
			return false;
	}

	return true;
}

int main(int argc, char** argv)
{
	cin >> n;
	a.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());

	for(int i = 0; i < n; ++i)
		if(needrem(i))
			++ans;

	cout << ans << endl;

	return 0;
}