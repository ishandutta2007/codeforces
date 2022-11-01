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

bool prime(i64 x)
{
	for (i64 i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
vector<i64> factor (i64 x)
{
	vector<i64> res;
	for (i64 i = 1; i*i <= x; i++)
		if (x%i == 0)
			res.pb(i), res.pb(x/i);
	if ((int)res.size() >= 2 && res.back() == res[res.size() - 2])
		res.pop_back();
	sort(all(res));
	return res;
}


int main()
{
	i64 n;
	cin >> n;
	if (prime(n))
	{
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	vector<i64> a = factor(n);
	vector<i64> b(a.size(), 0);
	forn(i, a.size())
		if (prime(a[i]))
			b[i] = 1;
		else
		{
			for (int j = 1; j < i; j++)
				if (a[i]%a[j] == 0 && !b[j])
				{
					b[i] = 1;
					break;
				}
		}
	if (b.back() == 0)
		cout << 2 << endl;
	else
	{
		cout << 1 << endl;
		for (int j = 1; j < (int)a.size()-1; j++)
			if (a.back()%a[j] == 0 && !b[j])
			{
				cout << a[j] << endl;
				return 0;
			}
	}
	
	return 0;
}