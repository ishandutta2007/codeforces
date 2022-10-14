#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n, k;
int bio[MAXN];
vector <int> v[MAXN];

int ask (int cnt) {
    vector <int> q;
    for (int i = 0; i <= cnt; i++) {
        for (auto x : v[i]) q.push_back(x);
    }
    cout << "? " << q.size() << " ";
    for (auto x : q) cout << x << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int zad (int ind) {
    vector <int> q;
    for (int i = 0; i < k; i++) {
        if (i == ind) continue;
        for (auto x : v[i]) q.push_back(x);
    }
    cout << "? " << q.size() << " ";
    for (auto x : q) cout << x << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(bio, 0, sizeof bio);
        for (int i = 0; i < n; i++) v[i].clear();
        int r = 0;
        for (int i = 0; i < k; i++) {
            int br; cin >> br;
            for (int j = 0; j < br; j++) {
                int x; cin >> x;
                bio[x] = 1; r++;
                v[i].push_back(x);
            }
        }
        if (r < n) {
            k++;
            for (int i = 1; i <= n; i++) {
                if (bio[i] == 0) v[k - 1].push_back(i);
            }
        }
        int mx = ask(k - 1);
        int lo = 0, hi = k-1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ask(mid) == mx) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int val = zad(lo);
        cout << "! ";
        for (int i = 0; i < k; i++) {
            if (i == k-1 && r < n) break;
            if (i == lo) cout << val << " "; else cout << mx << " ";
        }
        cout << endl;
        string s; cin >> s;
    }
    return 0;
}