#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k;
vi ans;
vector<pair<int, int>> a;

int calc_mid(int l, int r, int p) {
    int mid = l - 1;
    for(int i = l; i <= r; i++) {
        if(!((a[i].first >> p) & 1)) {
            mid = i;
        }
    }
    return mid;
}

bool solve1(int l1, int r1, int l2, int r2, int p) {
    if(l1 > r1 || l2 > r2) return false;
    if(p == -1) {
        ans.push_back(a[l1].second);
        ans.push_back(a[r2].second);
        return true;
    }
    int mid1 = calc_mid(l1, r1, p);
    int mid2 = calc_mid(l2, r2, p);
    int herek = (k >> p) & 1;
    bool there00 = (mid1 >= l1);
    bool there01 = (mid1 < r1);
    bool there10 = (mid2 >= l2);
    bool there11 = (mid2 < r2);
    if(herek == 0) {
        if(there00 && there11) {
            ans.push_back(a[l1].second);
            ans.push_back(a[r2].second);
            return true;
        }
        if(there01 && there10) {
            ans.push_back(a[r1].second);
            ans.push_back(a[l2].second);
            return true;
        }
        return solve1(l1, r1, l2, r2, p - 1);
    }
    if(solve1(l1, mid1, mid2 + 1, r2, p - 1)) return true;
    return solve1(mid1 + 1, r1, l2, mid2, p - 1);
}

void solve(int l, int r, int p) {
    if(l > r) return;
    if(l == r) {
        ans.push_back(a[l].second);
        return;
    }
    int mid = calc_mid(l, r, p);
    if((1 << p) > k) {
        solve(l, mid, p - 1);
        solve(mid + 1, r, p - 1);
        return;
    }
    if(!solve1(l, mid, mid + 1, r, p)) {
        ans.push_back(a[l].second);
    }

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
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    if(k == 0) {
        cout << n << '\n';
        for(int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        return 0;
    }
    sort(a.begin(), a.end());
    solve(0, n - 1, 29);
    if(ans.size() < 2) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << '\n';
    for(const auto& el : ans) {
        cout << el + 1 << ' ';
    }
}