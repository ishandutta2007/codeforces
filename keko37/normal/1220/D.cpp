#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n;
llint a[MAXN], ok[MAXN];
vector <llint> v[65], sol;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        llint br = 0, val = a[i];
        while (val % 2 == 0) {
            val /= 2;
            br++;
        }
        v[br].push_back(i);
    }
    int ind = -1, mx = 0;
    for (int i=0; i<63; i++) {
        if (v[i].size() > mx) {
            mx = v[i].size();
            ind = i;
        }
    }
    for (auto x : v[ind]) ok[x] = 1;
    for (int i=1; i<=n; i++) if (!ok[i]) sol.push_back(a[i]);
    cout << sol.size() << endl;
    for (auto x : sol) cout << x << " ";
    return 0;
}