//#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 100 * 1000 + 13;

bool good[30];
char s[N];
int k;
int cnt[30];

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	
	gets(s);
	cin >> k;
	
	int n = strlen(s);
	
	forn(i, n)
		cnt[s[i] - 'a']++;
		
	vector <pt> v;
	forn(i, 26)
		v.pb(mp(cnt[i], i));
		
	sort(all(v));
	
	int sum = 0;
	int idx = 0;
	
	forn(i, sz(v))
	{
		sum += v[i].ft;
		
		if (sum > k)
			break;
			
		idx++;
	}
	
	for (int i = idx; i < sz(v); i++)
		good[v[i].sc] = true;
		
	string ans = "";
	
	forn(i, n)
		if (good[s[i] - 'a'])
			ans.pb(s[i]);
			
	cout << sz(v) - idx << endl;
	
	puts(ans.c_str());

	return 0;
}