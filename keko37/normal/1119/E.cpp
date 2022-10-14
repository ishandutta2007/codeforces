#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

llint n, sol;
llint a[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) v.push_back(i);
    }
    int rig = n, lef = 1;
    while (1 <= rig && lef <= n) {
        if (a[rig] <= 1) {
            rig--;
            continue;
        }
        if (a[lef] == 0) {
            lef++;
            continue;
        }
        if (!v.empty()) {
            if (v.back() > rig) {
                v.pop_back();
                continue;
            }
            sol++;
            a[rig] -= 2;
            a[v.back()]--;
            v.pop_back();
        } else {
            if (lef > rig) break;
            if (lef == rig) {
                sol += a[lef] / 3;
                a[lef] %= 3;
                break;
            } else {
                llint x = a[lef];
                llint y = a[rig];
                if (2*x <= y) {
                    sol += x;
                    a[lef] = 0;
                    a[rig] -= 2*x;
                } else {
                    sol += y/2;
                    a[lef] -= y/2;
                    a[rig] = 0;
                }
            }
        }
    }
    cout << sol;
    return 0;
}