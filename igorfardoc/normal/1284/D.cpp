#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll p[200000];
const ll mod = 1000000000000000001ll;
void precalc() {
    p[0] = 1;
    for(int i = 1; i < 200000; i++) {
        p[i] = p[i - 1] * 2 % mod;
    }
}
vi op;
ll t[maxn * 4 + 7];

void clear_tree() {
    for(const auto& el : op) {
        t[el] = 0;
    }
    op.clear();
}

void update(int now, int l, int r, int l1, int r1, ll val) {
    if(l > r1 || l1 > r) {
        return;
    }
    op.push_back(now);
    if(l1 <= l && r <= r1) {
        t[now] = (t[now] + val) % mod;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
}

ll get_val(int now, int l, int r, int pos) {
    if(l == r) {
        return t[now];
    }
    int mid = (l + r) / 2;
    if(mid >= pos) {
        return (get_val(now * 2, l, mid, pos) + t[now]) % mod;
    }
    return (get_val(now * 2 + 1, mid + 1, r, pos) + t[now]) % mod;
}


vector<ll> doit(vector<pair<int, int>> mass) {
    vector<array<int, 3>> a;
    int n = mass.size();
    clear_tree();
    for(int i = 0; i < n; i++) {
        a.push_back({mass[i].first, mass[i].second, i});
    }
    sort(a.begin(), a.end());
    vector<ll> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] + p[a[i - 1][2]]) % mod;
    }
    for(int i = 0; i < n; i++) {
        int l = i;
        int r = n;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(a[mid][0] > a[i][1]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        int l1 = i + 1;
        int r1 = l;
        ll here = p[a[i][2]];
        if(r1 >= l1) {
            update(1, 0, n - 1, l1, r1, here);
        }
        ll after = (pref[r1 + 1] - pref[l1] + mod) % mod;
        //cout << i << ' ' << here << ' ' << after << ' ' << l1 << ' ' << r1 << endl;
        update(1, 0, n - 1, i, i, after);
        //cout << get_val(1, 0, n - 1, 1) << endl;
    }
    vector<ll> res(n);
    for(int i = 0; i < n; i++) {
        res[a[i][2]] = get_val(1, 0, n - 1, i);
    }
    return res;
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
    precalc();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    auto a1 = doit(a);
    auto b1 = doit(b);
    /*for(const auto& el : a1) {
        cout << el << ' ';
    }
    cout << '\n';
    for(const auto& el : b1) {
        cout << el << ' ';
    }*/
    cout << '\n';
    if(a1 == b1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}