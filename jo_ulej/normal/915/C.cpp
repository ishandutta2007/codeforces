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

string rev_sort(string x)
{
	sort(x.begin(), x.end());
	reverse(x.begin(), x.end());

	return x;
}

map<string, string> mem;

string dp(string a, string b)
{
	string ret;
	sort(a.begin(), a.end());

	if(mem.find(a) != mem.end())
		return mem[a];

	for(int j = 0; j < a.size(); ++j)
	{
		if(a[j] <= b[0])
		{
			string na = a;
			swap(na[0], na[j]);		

			string temp;
		   
			if(a[j] == b[0])
				temp = na[0] + dp(na.substr(1, na.size() - 1), b.substr(1, b.size() - 1));
			else
				temp = na[0] + rev_sort(na.substr(1, na.size() - 1));

			if(temp.size() != a.size())
				continue;

			if(ret == "" || temp > ret)
				ret = temp;
		}
	}

	mem.insert(make_pair(a, ret));

	return ret;
}

void solve()
{
	string a, b;

	cin >> a >> b;

	if(a.size() != b.size())
	{
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		cout << a << endl;
	}
	else
	{
		cout << dp(a, b) << endl;
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}