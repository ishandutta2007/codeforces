#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 1e7 + 9;

void solve()
{
	vector<ll> alice, bob, nobody, both;
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string type;
		ll influence;

		cin >> type >> influence;

		if(type == "00")
			nobody.push_back(influence);

		if(type == "10")
			alice.push_back(influence);

		if(type == "01")
			bob.push_back(influence);

		if(type == "11")
			both.push_back(influence);
	}

	sort(nobody.begin(), nobody.end());
	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	sort(both.begin(), both.end());

	reverse(nobody.begin(), nobody.end());
	reverse(alice.begin(), alice.end());
	reverse(bob.begin(), bob.end());
	reverse(both.begin(), both.end());

	if(both.size() == 0 && (alice.size() == 0 || bob.size() == 0))
	{
		cout << "0" << endl;

		return;
	}

	int a = 0, b = 0, m = 0;
	ll ans = 0;

	for(auto el: both)
		++a, ++b, ++m, ans += el;

	if(alice.size() > bob.size())
		swap(alice, bob), swap(a, b);

	for(int i = 0; i < alice.size(); ++i)
		++a, ++b, m += 2, ans += alice[i] + bob[i];

	int i = alice.size();
	int j = 0;

	for(;;)
	{
		bool stopped = true;

		if(i < bob.size() && j < nobody.size())
		{
			bool fi = (2 * a >= m + 1 && 2 * (b + 1) >= m + 1);
			bool fj = (2 * a >= m + 1 && 2 * b >= m + 1);

			if(fi && fj)
			{
				if(bob[i] > nobody[j])
					ans += bob[i++], ++b;
				else
					ans += nobody[j++];

				++m;
				stopped = false;
			}

		}
		else if(i < bob.size())
		{
			//cout << "m,a,b=" << m << " " << a << " " << b << endl;
			bool fi = (2 * a >= m + 1 && 2 * (b + 1) >= m + 1);

			if(fi)
				ans += bob[i++], ++b, ++m, stopped = false;
		}
		else if(j < nobody.size())
		{
			bool fj = (2 * a >= m + 1 && 2 * b >= m + 1);

			if(fj)
				ans += nobody[j++], ++m, stopped = false;
		}

		if(stopped)
			break;

		DBG(i); DBG(j);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}