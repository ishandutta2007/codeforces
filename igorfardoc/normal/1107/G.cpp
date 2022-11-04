#include<bits/stdc++.h>
#define inf 1000000000000000000ll
#define maxn 300000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, a;
int d[maxn], c[maxn];
ll ans = 0;

void solve(vi& c, vi& d, int mid) {
    int n = c.size();
    int now = mid + 1;
    ll maxnow = 0;
    ll curr = 0;
    ll mx = 0;
    ll res = a - c[mid];
    for(int i = mid - 1; i >= 0; i--) {
        res += a - c[i];
        mx = max(mx, (ll)(d[i + 1] - d[i]) * (d[i + 1] - d[i]));
        while(now < n && (ll)(d[now] - d[now - 1]) * (d[now] - d[now - 1]) <= mx) {
            curr += a - c[now];
            maxnow = max(maxnow, curr);
            ++now;
        }
        //cout << res - mx + maxnow << ' ' << res << ' ' << mx << ' ' << maxnow << endl;
        ans = max(ans, res - mx + maxnow);
    }

}

void rec(int l, int r) {
    if(l > r) return;
    if(l == r) {
        ans = max(ans, (ll)a - c[l]);
        return;
    }
    int mid = (l + r) / 2;
    vi d1;
    vi c1;
    for(int i = l; i <= r; i++) {
        d1.push_back(d[i]);
        c1.push_back(c[i]);
    }
    solve(c1, d1, (l + r) / 2 - l);
    reverse(c1.begin(), c1.end());
    reverse(d1.begin(), d1.end());
    solve(c1, d1, r - (l + r) / 2);
    rec(l, mid);
    rec(mid + 1, r);
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
    cin >> n >> a;
    for(int i = 0; i < n; i++) {
        cin >> d[i] >> c[i];
    }
    rec(0, n - 1);
    cout << ans;
}