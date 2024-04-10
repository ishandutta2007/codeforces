#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

const int MAXN = 30;

int a[MAXN];

char b[MAXN], c[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s; cin >> s;

	int n = s.size();
	rep(i, n) {
      if(i && s[i] == s[i - 1]) {
         cout << "Impossible";
         return 0;
      }
      a[s[i] - 'A'] ++;
	}

	int j = 0;
	rep(i, 26) {
      if(a[i] == 2) {
         j = i;
      }
	}

	string l = "", r = "", m = "";
	int tmp = 0;
	while(s[tmp] - 'A' != j) {
      l += s[tmp];
      tmp ++;
	}
	tmp += 1;
	while(s[tmp] - 'A' != j) {
      m += s[tmp];
      tmp ++;
	}
	tmp = n - 1;
	while(s[tmp] - 'A' != j) {
      r += s[tmp];
      tmp --;
	}

	int x = l.size(), y = r.size();

	if(x > y) {
      swap(x, y);
      swap(l, r);
	}

	tmp = 0;
	while(y > x && y > 1) {
      b[tmp / 2] = r[tmp];
      c[tmp / 2] = r[tmp + 1];
      y -= 2;
      tmp += 2;
	}

	int poc = tmp / 2;
	rep(i, y) {
      b[poc] = r[i + tmp];
      poc ++;
	}
	poc = tmp / 2;
	rep(i, x) {
      c[poc] = l[i];
      poc ++;
	}

	if(x >= y) {
      b[tmp / 2 + y] = j + 'A';
      rep(i, 13 - tmp / 2 - y - 1) {
         b[tmp / 2 + y + 1 + i] = m[i];
      }
      rep(i, 13 - tmp / 2 - x) {
         c[13 - 1 - i] = m[i + 13 - tmp / 2 - y - 1];
      }
	}
	else {
      c[tmp / 2 + x] = j + 'A';
      rep(i, 13 - tmp / 2 - y) {
         b[tmp / 2 + y + i] = m[i];
      }
      rep(i, 13 - tmp / 2 - x - 1) {
         c[13 - 1 - i] = m[i + 13 - tmp / 2 - y];
      }
	}
	rep(i, 13) cout << b[i];
	cout << endl;
	rep(i, 13) cout << c[i];
}