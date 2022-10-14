#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, m, sol;
int l[11] [MAXN], p[11] [MAXN], c[11];

bool pomak () {
    if (c[0] == n-1) return 0;
    int val = l[0] [c[0] + 1];
    for (int i=0; i<m; i++) {
        if (c[i] == n-1) return 0;
        if (l[i] [c[i] + 1] != val) return 0;
    }
    for (int i=0; i<m; i++) {
        c[i]++;
    }
    return 1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> l[i] [j];
            p[i] [l[i] [j]] = j;
        }
    }
    for (int i=0; i<m; i++) {
        c[i] = p[i] [l[0] [0]];
    }
    int rig = 0;
    for (int lef = 0; lef < n; lef++) {
        if (lef > rig) {
            rig = lef;
            for (int i=0; i<m; i++) {
                c[i] = p[i] [l[0] [lef]];
            }
        }
        while (pomak()) rig++;
        sol += rig - lef + 1;
    }
    cout << sol;
    return 0;
}