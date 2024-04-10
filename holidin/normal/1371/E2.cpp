#include <bits/stdc++.h>
//#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 12;
bool debag = false;

int cnt[N], mx[N];

int w[N], a[N];


void run2(int n, int p, vector<int> a) {
    int x, i, j, xmin = 1e9 + 1, q, l, r;
    string s;
    vector <int> ans;
    for (int x = 1; x <= 2000; ++x) {
        for (int i = 0; i < n; ++i)
            w[i] = 0;
        bool can = true;
        for (int i = 0; i < n; ++i)
        if (a[i] - x >= n) {
            can = 0;
        } else
            ++w[max((int)0, a[i] - x)];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            if (sum <= 0 || sum % p == 0)
                can = 0;
            --sum;
        }
        if (can)
            ans.push_back(x);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
}


void run() {
    int n, x, i, j, xmin = 1e9 + 1, q, l, r, p;
    string s;
    cin >> n >> p;
    vector <int> a(n);
    for (i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int minx = 1;
    for (i = 0; i < n; ++i)
        minx = max(minx, a[i] - i);
    for (i = 0; i < n; ++i) {
        a[i] = max(0, a[i] - minx);
        ++cnt[a[i]];
    }
    int sum = 0, all = 0;
    for (int i = 0; i < n; ++i)
        mx[i] = -1;
    int t = -1;
    for (i = 0; i < n; ++i) {
        sum += cnt[i];
        all += cnt[i];
        if (all >= p && t == -1)
            t = i;
        mx[(p - sum % p) % p] = max(mx[(p - sum % p) % p], i);
        --sum;
    }
    vector<int> ans;
    for (int x = 0; x < t; ++x)
    if (mx[x % p] < x)
        ans.push_back(minx + x);
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    run();
}