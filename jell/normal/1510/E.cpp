#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define EPS (long double)0.00000001
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

char c[N][20];
long double ssx[N];
long double ssy[N];
long double sss[N];
vi idx[20];

int main() {
	rep(i, N) {
		rep(j, 20)c[i][j] = 0;
	}
	int n;
	int k;
	int x;
	int itr = 0;
	bool v;
	long double sx, sy, ss;
	long double xx, yy, s;
	cin >> n;
	n /= 2;
	k = 1 << n;
	int a[20];
	rep(i, k) {
		x = i;
		a[0] = 0;
		v = true;
		rep(j, n) {
			if (x % 2 == 0) {
				c[itr][j] = '(';
				a[j + 1] = a[j] + 1;
			}
			else {
				c[itr][j] = ')';
				a[j + 1] = a[j] - 1;
			}
			x /= 2;
			if (a[j + 1] < 0)v = false;
		}
		if (v) {
			sx = 0;
			sy = 0;
			ss = 0;
			rep(i, n) {
				if (a[i] < a[i + 1]) {
					xx = (long double)((2 * i) + 1);
					xx = xx / (2.0000);
					yy = (long double)a[i];
					yy /= 2.00;
					s = (long double)a[i];
					sx += (xx*s);
					sy += (yy*s);
					ss += s;
					xx = (long double)((3 * i) + 2);
					xx = xx / (3.0000);
					yy = (long double)1;
					yy /= 3.00;
					yy += (long double)a[i];
					s = (long double)0.50000;
					sx += (xx*s);
					sy += (yy*s);
					ss += s;
				}
				else {
					xx = (long double)((2 * i) + 1);
					xx = xx / (2.0000);
					yy = (long double)a[i + 1];
					yy /= 2.00;
					s = (long double)a[i + 1];
					sx += (xx*s);
					sy += (yy*s);
					ss += s;
					xx = (long double)((3 * i) + 1);
					xx = xx / (3.0000);
					yy = (long double)1;
					yy /= 3.00;
					yy += (long double)a[i + 1];
					s = (long double)0.50000;
					sx += (xx*s);
					sy += (yy*s);
					ss += s;
				}
			}
			ssx[itr] = sx / ss;
			ssy[itr] = sy / ss;
			sss[itr] = ss;
			idx[a[n]].pb(itr);
			itr++;
		}
	}
	long double gx, gy;
	long double sssx, sssy, ssss;
	char ans[40];
	rep(i, 40)ans[i] = 0;
	int sz;
	cin >> gx >> gy;
	rep(ii, n + 1) {
		sz = idx[ii].size();
		rep(i, sz) {
			rep(j, sz) {
				sssx = (sss[idx[ii][i]] * ssx[idx[ii][i]]) + ((((long double)(2 * n)) - ssx[idx[ii][j]])*sss[idx[ii][j]]);
				sssy = (sss[idx[ii][i]] * ssy[idx[ii][i]]) + (sss[idx[ii][j]] * ssy[idx[ii][j]]);
				ssss = sss[idx[ii][i]] + sss[idx[ii][j]];
				sssx /= ssss;
				sssy /= ssss;
				if ((abs(sssx - gx) < EPS) && (abs(sssy - gy) < EPS)) {
					rep(jj, n)ans[jj] = c[idx[ii][i]][jj];
					rep(jj, n) {
						if (c[idx[ii][j]][jj] == '(')ans[2 * n - 1 - jj] = ')';
						else ans[2 * n - 1 - jj] = '(';
					}
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}