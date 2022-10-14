#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n;
int sol[MAXN];
map <int, int> mp, rig;

pi pitaj (int lef, int rig) {
    cout << "? " << lef << " " << rig << endl;
    int x, f;
    cin >> x >> f;
    return {x, f};
}

void calc (int lo, int hi) {
    if (lo > hi) return;
    pi res = pitaj(lo, hi);
    int x = res.first, f = res.second;
    if (mp.find(x) != mp.end()) {
        int poc = hi - f + 1;
        int len = mp[x];
        for (int i = 0; i < len; i++) sol[poc + i] = x;
        rig[x] = poc + len - 1;
        mp.erase(x);
        calc(lo, poc - 1);
    } else {
        mp[x] = f;
        for (int i = lo; i <= hi; i += f) {
            calc(i, i + f - 1);
            if (mp.find(x) == mp.end()) break;
        }
        calc(rig[x] + 1, hi);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    calc(1, n);
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << sol[i] << " "; cout << endl;
    return 0;
}