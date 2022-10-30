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
	int n, k, ans = 0;
	string str;

	cin >> n >> k >> str;

	for(char chr = 'a'; chr <= 'z'; ++chr)
	{
		int level = 0;

		for(int i = 0; i < n;)
		{
			int j = i;

			while(j + 1 < n && str[j + 1] == str[i])
				++j;

			int len = j - i + 1;

			if(str[i] == chr)
				level += len / k;

			i = j + 1;
		}

		ans = max(ans, level);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}