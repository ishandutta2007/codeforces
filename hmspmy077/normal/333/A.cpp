#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

typedef long long int64;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define ms(a,x)



int main()
{
	#ifdef LOCAL_TEST
	//	freopen("a.in","r",stdin);
	//	freopen("a.out","w",stdout);
	#endif
	int64 n;
	cin >> n;
	for (int64 i = 3; ; i *= 3LL)
		if (n % i != 0)
		{
			cout << n / i + 1 <<endl;
			return 0;
		}
	return 0;
}