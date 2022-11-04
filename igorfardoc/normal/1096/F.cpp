#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int t[maxn * 4 + 7];

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) res = ((ll)res * a) % mod;
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}

void update(int now, int l, int r, int pos, int val) {
    if(l == r) {
        t[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos) {
        update(now * 2, l, mid, pos, val);
    } else {
        update(now * 2 + 1, mid + 1, r, pos, val);
    }
    t[now] = t[now * 2] + t[now * 2 + 1];
}

int get(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) return 0;
    if(l1 <= l && r <= r1) return t[now];
    int mid = (l + r) / 2;
    return get(now * 2, l, mid, l1, r1) + get(now * 2 + 1, mid + 1, r, l1, r1);
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
    int ans = 0;
    int am = 0;
    set<int> all;
    for(int i = 0; i < n; i++) {
        all.insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        if(a[i] == -2) continue;
        all.erase(a[i]);
        ++am;
        ans = (get(1, 0, n - 1, a[i], n - 1) + ans) % mod;
        update(1, 0, n - 1, a[i], 1);
    }
    int other = n - am;
    ans = (ans + (ll)other * (other - 1) % mod * obr(4)) % mod;
    vi all1;
    for(const auto& el : all) {
        all1.push_back(el);
    }
    int nowsum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == -2) {
            ans = (ans + (ll)nowsum * obr(other)) % mod;
        } else {
            int id1 = lower_bound(all1.begin(), all1.end(), a[i]) - all1.begin();
            nowsum = (nowsum + id1) % mod;
        }
    }
    nowsum = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == -2) {
            ans = (ans + (ll)nowsum * obr(other)) % mod;
        } else {
            int id1 = lower_bound(all1.begin(), all1.end(), a[i]) - all1.begin();
            nowsum = (nowsum + all1.size() - id1) % mod;
        }
    }
    cout << ans;
}