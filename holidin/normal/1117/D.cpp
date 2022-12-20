#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const long long mod = 1e9 + 7;

vector <vector <long long> > v;
long long n, k;

vector <vector <long long> > mul(vector <vector <long long> > a, vector <vector <long long> > b) {
    vector <vector<long long> > c;
    c.resize(a.size());
    for (int i = 0; i < a.size(); ++i) {
        c[i].resize(a[i].size());
        for (int j = 0; j < a[i].size(); ++j) {
            c[i][j] = 0;
            for (int l = 0; l < a.size(); ++l)
                c[i][j] = (c[i][j] + a[i][l] * b[l][j]) % mod;
        }
    }
    return c;
}

vector <vector <long long> > bp(vector <vector <long long> > a, long long st) {
    if (st == 1)
        return a;
    else if (st % 2 == 0)
            return bp(mul(a, a), st / 2);
        else
            return mul(bp(mul(a, a), st / 2), a);
}

int main() {
    int i, j;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.resize(k);
    for (i = 0; i < k; ++i) {
        v[i].resize(k);
        v[i][(i + 1) % k] = 1;
    }
    v[0][0] = 1;
    v = bp(v, n);
    cout << v[0][0] << endl;
}