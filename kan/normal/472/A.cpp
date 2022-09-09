#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0) cout << n - 4 << ' ' << 4 << endl;
	else cout << 9 << ' ' << n - 9 << endl;
	return 0;
}