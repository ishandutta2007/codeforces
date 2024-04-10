#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n, k;
int h[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < k; i++) {
            int pos = 1;
            while (pos < n && h[pos] >= h[pos + 1]) pos++;
            if (pos < n) {
                h[pos]++;
                v.push_back(pos);
            } else break;
        }
        if (k <= v.size()) cout << v[k - 1] << '\n'; else cout << "-1\n";
    }
    return 0;
}