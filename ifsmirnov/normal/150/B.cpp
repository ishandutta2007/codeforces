#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define unq(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define lb lower_bound
const int inf = 1e9+100500;
const int maxn = 100500;
const int mod = 1000000007;
int mmul(int x, int y) {return (i64)x*y%mod;}
int madd(int x, int y) {return (x+y)%mod;}

int mpow (int x, int k)
{
	if (k == 0)
		return 1;
	return mmul(x, mpow(x, k-1));
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (k > n)
		cout << mpow(m, n) << endl;
	else if (k == 1)
		cout << mpow(m, n) << endl;
	else if (k == n)
	{
		if (k%2 == 0)
			cout << mpow(m, n/2) << endl;
		else
			cout << mpow(m, n/2+1) << endl;
	}
	else if (k%2 == 0)
		cout << m << endl;
	else
		cout << mpow(m, 2) << endl;
		
	return 0;
}