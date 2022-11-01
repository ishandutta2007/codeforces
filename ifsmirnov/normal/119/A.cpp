#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define gcd __gcd

int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	
	while (1)
	{
		int t = gcd(a, n);
		if (t > n)
		{
			cout << 1 << endl;
			return 0;
		}
		else
			n -= t;
			
		t = gcd(b, n);
		if (t > n)
		{
			cout << 0 << endl;
			return 0;
		}
		else
			n -= t;
	}
	
	return 0;
}