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
#include <unordered_map>

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

const int N = 1000*1000;

int n;
int m;

vector<pair<int, ii> > q[N + 1];
ii v[N + 1];
int o;
unordered_map<int, int> num;
int f[N + 1];
int res[N + 1];

int getx (int x) {
	if (num.count (x)) re num[x];
	num[x] = o++;
	re o - 1;
}

int getf (int x) {
	int y = 0;
	while (x > 0) {
		y += f[x];
		x = (x & (x + 1)) - 1;
	}
	re y;
}

void add (int x, int y, int n) {
	while (x <= n) {
		f[x] += y;
		x |= x + 1;
	}
}

string get (int x) {
	string s = "";
	if (x == 0) s = "0";
	while (x) {
		s = s + char (x % 10 + '0');
		x /= 10;
	}
	reverse (all (s));
	re s;
}

char h[100];
char *ch;

int read () {
	int x = 0;
	while (!(*ch >= '0' && *ch <= '9')) ch++;
	while (*ch >= '0' && *ch <= '9') {
		x = x * 10 + (*ch) - '0';
		ch++;
	}
	re x;
}

int main () {
	scanf ("%d", &n);
	gets (h);
	for (int i = 0; i < n; i++) {
		int a, t, x;
		gets (h);
		ch = h;
		a = read ();
		t = read ();
		x = read ();
//		sscanf (h, "%d%d%d", &a, &t, &x);
//		scanf ("%d%d%d", &a, &t, &x);
		x = getx (x);
		q[x].pb (mp (i, mp (a, t)));
		res[i] = -1e9;
	}
//	cerr << clock () << endl;
	for (int i = 0; i < o; i++) {
		int len = sz (q[i]);
		for (int j = 0; j < len; j++)
			v[j] = mp (q[i][j].se.se, j);
		sort (v, v + len);
		for (int j = 0; j < len; j++) q[i][v[j].se].se.se = j + 1;
		for (int j = 1; j <= len; j++) f[j] = 0;
		for (int j = 0; j < len; j++)
			if (q[i][j].se.fi == 1)
				add (q[i][j].se.se, 1, len);
			else
			if (q[i][j].se.fi == 2)	
				add (q[i][j].se.se, -1, len);
			else
				res[q[i][j].fi] = getf (q[i][j].se.se);	
	}
//	cerr << clock () << endl;
	string ans = "";
	bool f = true;
	for (int i = 0; i < n; i++)
		if (res[i] >= -1e8) {
			if (!f) ans += "\n";
			f = false;
			ans += get (abs (res[i]));
		}	
	puts (ans.c_str ());
//	cerr << clock () << endl;
	return 0;
}