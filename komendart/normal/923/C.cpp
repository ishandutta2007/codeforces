#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int len = 30;
const int maxmem = len * 3 * (int) 1e5 + 100;

int go[maxmem][2];
int cnt[maxmem];
int last = 0;

void add(int x) {
    int node = 0;
    for (int i = len - 1; i >= 0; --i) {
        int c = (x >> i) & 1;
        if (!go[node][c]) {
            go[node][c] = ++last;
        }
        node = go[node][c];
        ++cnt[node];
    }
}

int get(int x) {
    int node = 0;
    int ans = 0;
    for (int i = len - 1; i >= 0; --i) {
        int c = (x >> i) & 1;
        if (!go[node][c] || cnt[go[node][c]] == 0) {
            c ^= 1;
            ans ^= 1 << i;
        }
        node = go[node][c];
        --cnt[node];
    }
    return ans;
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(x);
    }
    for (int i = 0; i < n; ++i) {
        cout << get(a[i]) << ' ';
    }
    
}