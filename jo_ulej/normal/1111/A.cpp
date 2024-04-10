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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

bool is_vowel(char x)
{
	return (x == 'a' || x == 'e' || x == 'u' || x == 'i' || x == 'o');
}

void solve()
{
	string s, t;
	cin >> s >> t;

	if(s.size() != t.size())
	{
		cout << "No" << endl;

		return;
	}

	for(int i = 0; i < s.size(); ++i)
	{
		if(is_vowel(s[i]) != is_vowel(t[i]))
		{
			cout << "No" << endl;

			return;
		}
	}

	cout << "Yes" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}