#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef pair<int, int> pii;
typedef long long i64;

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int n, k;
	cin >> n >> k;
	vector<pii> a(n);
	forn(i, n) cin >> a[i].fi >> a[i].se, a[i].fi *= -1;
	sort(a.begin(), a.end());
	cout << count(a.begin(), a.end(), a[k-1]) << endl;
	
	return 0;
}