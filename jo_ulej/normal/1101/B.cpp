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
typedef long double ld;

const ll mod = 1e9 + 7;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();

	int pref = 0;

	while(pref < n && s[pref] != '[')
		++pref;

	if(pref >= n)
	{
		cout << "-1" << endl;

		return;
	}

	while(pref < n && s[pref] != ':')
		++pref;

	if(pref >= n)
	{
		cout << "-1" << endl;

		return;
	}

	int suff = n - 1;

	while(suff >= 0 && s[suff] != ']')
		--suff;

	if(suff < 0)
	{
		cout << "-1" << endl;

		return;
	}

	while(suff >= 0 && s[suff] != ':')
		--suff;

	if(suff < 0)
	{
		cout << "-1" << endl;

		return;
	}

	if(pref >= suff)
	{
		cout << "-1" << endl;

		return;
	}

	int ans = 4;

	for(int i = pref + 1; i <= suff - 1; ++i)
		if(s[i] == '|')
			++ans;

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}