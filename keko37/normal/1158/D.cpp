#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 2005;
const int INF = 1000000007;

int n, curr, mx = -INF;
string s;
llint x[MAXN], y[MAXN];
bool bio[MAXN];
vector <int> v, sol;

inline llint ccw (int a, int b, int c) {
    return x[a] * (y[b] - y[c]) + x[b] * (y[c] - y[a]) + x[c] * (y[a] - y[b]);
}

bool cmp (int i1, int i2) {
    return ccw(curr, i1, i2) < 0;
}

void rjesi () {
    for (int i=0; i<n; i++) {
        bio[curr] = 1;
        sol.push_back(curr);
        if (i == n-1) break;
        v.clear();
        for (int j=1; j<=n; j++) {
            if (!bio[j]) v.push_back(j);
        }
        sort(v.begin(), v.end(), cmp);
        if (s[i] == 'R') curr = v[0]; else curr = v.back();
    }
}

int main () {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > mx) {
            mx = x[i];
            curr = i;
        }
    }
    cin >> s;
    s += '.';
    rjesi();
    for (int i=0; i<n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}