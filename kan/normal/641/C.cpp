#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

int n;
int m;

int res[1000100];

string get (int x) {
	string s = "";
	while (x) {
		s = s + char (x % 10 + '0');
		x /= 10;
	}
	reverse (all (s));
	re s;
}

int main () {
	scanf ("%d%d", &n, &m);
	int pos0 = 0, pos1 = 1;
	for (int i = 0; i < m; i++) {
		int t;
		scanf ("%d", &t);
		if (t == 1) {
			int x;
			scanf ("%d", &x);
			if (x < 0) x += n;
			pos0 += x;
			pos1 += x;
			if (pos0 >= n) pos0 -= n;
			if (pos1 >= n) pos1 -= n;
		} else {
			pos0 ^= 1;
			pos1 ^= 1;
		}
	}
	for (int i = 0, j = pos0; i < n; i += 2, j = (j + 2) % n) res[j] = i;
	for (int i = 1, j = pos1; i < n; i += 2, j = (j + 2) % n) res[j] = i;
	string ans = "";
	for (int i = 0; i < n; i++) ans += get (res[i] + 1) + " ";
	puts (ans.c_str ());
	return 0;
}