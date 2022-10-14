#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, m, l, sol;
llint a[MAXN], t[MAXN];

void update (llint x, llint d) {
    int bio = t[x];
    a[x] += d;
    if (a[x] > l) t[x] = 1;
    if (t[x] == 1 && bio == 0) {
        int lef = t[x-1], rig = t[x+1];
        if (lef == 0 && rig == 0) sol++;
        if (lef == 1 && rig == 0);
        if (lef == 0 && rig == 1);
        if (lef == 1 && rig == 1) sol--;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> l;
    for (int i=1; i<=n; i++) {
        int val;
        cin >> val;
        update(i, val);
    }
    for (int i=0; i<m; i++) {
        llint tip, x, d;
        cin >> tip;
        if (tip == 0) {
            cout << sol << endl;
        } else {
            cin >> x >> d;
            update(x, d);
        }
    }
    return 0;
}