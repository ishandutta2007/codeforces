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
	string str, t;
	cin >> str;

	int len = 0;

	for(auto chr: str)
		if(chr != '*' && chr != '?')
			++len, t += chr;

	int min_len = len, max_len = len;

	for(auto chr: str)
	{
		if(chr == '*')
			--min_len, max_len = INT_INF;
		else if(chr == '?')
			--min_len;
	}

	int k;
	cin >> k;

	if(k >= min_len && k <= max_len)
	{
		if(k == len)
		{
			cout << t << endl;
		}
		else if(k < len)
		{
			string ans;
			int deleted = 0;

			for(int i = 0; i < str.size(); ++i)
			{
				if(i + 1 < str.size() && (str[i + 1] == '*' || str[i + 1] == '?'))
				{
					if(len - deleted > k)
					{
						++deleted;
					}
					else
					{
						ans += str[i];
					}

					++i;
				}
				else
				{
					ans += str[i];
				}
			}

			cout << ans << endl;
		}
		else // k > len
		{
			string ans;
			int added = 0;

			for(int i = 0; i < str.size(); ++i)
			{
				if(i + 1 < str.size() && (str[i + 1] == '*' || str[i + 1] == '?'))
				{
					while(len + added < k && str[i + 1] == '*')
					{
						ans += str[i];
						++added;
					}

					ans += str[i];

					++i;
				}
				else
				{
					ans += str[i];
				}
			}

			cout << ans << endl;
		}
	}
	else
	{
		cout << "Impossible" << endl;
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}