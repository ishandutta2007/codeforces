#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n;
int a[MAXN], br[MAXN];
vector <int> v;

int mex () {
    for (int i = 0; i <= n; i++) br[i] = 0;
    for (int i = 0; i < n; i++) br[a[i]]++;
    for (int i = 0; i <= n; i++) if (br[i] == 0) return i;
}

int ok () {
    for (int i = 0; i < n; i++) {
        if (a[i] != i) return i;
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        v.clear();
        while (1) {
            int ind = ok();
            if (ind == -1) break;
            int val = mex();
            if (val < n) {
                a[val] = val;
                v.push_back(val);
            } else {
                a[ind] = val;
                v.push_back(ind);
            }
       }
       cout << v.size() << '\n';
       for (auto x : v) cout << x + 1 << " "; cout << '\n';
    }
    return 0;
}