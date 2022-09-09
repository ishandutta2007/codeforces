#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int main()
{
	string s1, s2;
	map<string, int> dow;
	dow["monday"] = 0;
	dow["tuesday"] = 1;
	dow["wednesday"] = 2;
	dow["thursday"] = 3;
	dow["friday"] = 4;
	dow["saturday"] = 5;
	dow["sunday"] = 6;
	cin >> s1 >> s2;
	int a1 = dow[s1];
	int a2 = dow[s2];
	int shift = (a2 - a1 + 7) % 7;
	if (shift == 31 % 7 || shift == 28 % 7 || shift == 30 % 7) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}