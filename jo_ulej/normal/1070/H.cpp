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
	int n, q;
	map<string, set<string>> ans;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		for(int j = 0; j < s.size(); ++j)
		{
			for(int l = 1; j + l - 1 < s.size(); ++l)
			{
				string ss = s.substr(j, l);

				if(ans.find(ss) == ans.end())
					ans.insert(make_pair(ss, set<string>()));

				ans[ss].insert(s);
			}
		}
	}

	cin >> q;

	for(int i = 0; i < q; ++i)
	{
		string r;
		cin >> r;

		if(ans.find(r) == ans.end())
			cout << "0 - \n";
		else
			cout << ans[r].size() << " " << *ans[r].begin() << "\n";
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}