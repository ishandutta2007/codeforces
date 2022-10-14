#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1005;
const int MOD = 1000000007;

llint n;
llint a[MAXN], h[MAXN] [MAXN], b = 31337;
vector <int> v;

llint add (llint a, llint b) {
    a += b;
    if (a >= MOD) return a-MOD; return a;
}

llint mul (llint a, llint b) {
    return a*b % MOD;
}

bool moze (int x) {
    for (int i=1; i<=n; i+=x) {
        int lef = i, rig = i + x-1;
        if (rig > n) {
            if (h[lef] [n] != h[lef - x] [n - x]) return 0;
        } else {
            if (lef - x < 1) continue;
            if (h[lef] [rig] != h[lef - x] [rig - x]) return 0;
        }
    }
    return 1;
}

int main () {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=n; i>1; i--) {
        a[i] = a[i] - a[i-1];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            if (i == j) {
                h[i] [j] = a[i];
            } else {
                h[i] [j] = add(mul(h[i] [j-1], b), a[j]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (moze(i)) v.push_back(i);
    }
    cout << v.size() << endl;
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}