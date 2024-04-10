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

string decode(string x)
{
	if(x.size() == 1)
		return x;

	if(x.size() % 2 == 0)
		return decode(x.substr(0, x.size() - 1)) + x[x.size() - 1];
	else
		return decode(x.substr(1, x.size() - 1)) + x[0];
}

void solve()
{
	string str;
	cin >> str;

	cout << decode(str) << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}