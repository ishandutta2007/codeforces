#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;
const long long mod = 1e6 + 3;
long long a[N], suf[N], pr[N];


long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 1)
            return (bp((x * x) % mod, st / 2) * x) % mod;
        else
            return bp((x * x) % mod, st / 2);
}

int gauss (vector < vector<long long> > a, vector<long long> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col])== 0)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				long long c = (a[i][col] * bp(a[row][col], mod - 2)) % mod;
				for (int j=col; j<=m; ++j)
					a[i][j] = (a[i][j] - a[row][j] * c + mod * mod) % mod;
			}
		++row;
	}
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = (a[where[i]][m] * bp(a[where[i]][i], mod - 2)) % mod;
	for (int i=0; i<n; ++i) {
		long long sum = 0;
		for (int j=0; j<m; ++j)
			sum = (sum + ans[j] * a[i][j]) % mod;
		if (abs (sum - a[i][m]) > 0)
			return 0;
	}

	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return 1e9;
	return 1;
}

vector <long long> rel;

long long cnt(long long x) {
    long long sum = 0, st = 1;
    for (int j = 0; j < 11; ++j) {
        sum = (sum + rel[j] * st) % mod;
        st = (st * x) % mod;
    }
    return sum;
}

int main() {
    int i, j, n;
    long long k, sum = 0;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector <vector <long long> > v;
    vector <long long> as;
    v.resize(45);
    for (i = 0; i < 45; ++i) {
        long long x = rand() % mod, st = 1;
        v[i].resize(12);
        for (j = 0; j < 11; ++j) {
            v[i][j] = st;
            st = (st * x) % mod;
        }
        cout << "? " << x << endl;
        cin >> v[i][11];
    }
    int ans = gauss(v, as);
    for (i = 0; i < mod; ++i) {
        long long sum = 0, st = 1;
        for (j = 0; j < 11; ++j) {
            sum = (sum + as[j] * st) % mod;
            st = (st * i) % mod;
        }
        if (sum == 0) {
            cout << "! " << i << endl;
            exit(0);
        }
    }
    cout << "! " << -1 << endl;
}