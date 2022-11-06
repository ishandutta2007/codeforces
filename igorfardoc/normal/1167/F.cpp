#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1000000007;
int t[maxn * 4 + 7];
vi op;

void clear_tree() {
    for(const auto& el : op) {
        t[el] = 0;
    }
    op.clear();
}

void update(int now, int l, int r, int pos, int val) {
    op.push_back(now);
    t[now] = (t[now] + val) % mod;
    if(l == r) {
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos) {
        update(now * 2, l, mid, pos, val);
    } else {
        update(now * 2 + 1, mid + 1, r, pos, val);
    }
}

int get1(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) return 0;
    if(l1 <= l && r <= r1) return t[now];
    int mid = (l + r) / 2;
    return (get1(now * 2, l, mid, l1, r1) + get1(now * 2 + 1, mid + 1, r, l1, r1)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(n);
    vector<pair<int, int>> all(n);
    for(int i = 0; i < n; i++) {
        all[i] = {a[i], i};
    }
    sort(all.begin(), all.end());
    for(int i = 0; i < n; i++) {
        b[all[i].second] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans + (ll)(i + 1) * (n - i) % mod * a[i]) % mod;
        int here = get1(1, 0, n - 1, 0, b[i]);
        ans = (ans + (ll)a[i] * here % mod * (n - i)) % mod;
        update(1, 0, n - 1, b[i], i + 1);
    }
    clear_tree();
    for(int i = n - 1; i >= 0; i--) {
        int here = get1(1, 0, n - 1, 0, b[i]);
        ans = (ans + (ll)a[i] * here % mod * (i + 1)) % mod;
        update(1, 0, n - 1, b[i], n - i);
    }
    cout << ans;
}