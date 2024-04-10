#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

ll gcd(ll a, ll b)
{
    if (b == 0) return 0;
    return (a / b) + gcd(b, a % b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
	return 0;
}