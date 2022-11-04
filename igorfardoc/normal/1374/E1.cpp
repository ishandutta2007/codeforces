#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vi a, b, c;
    for(int i = 0; i < n; i++) {
        int val, al, bob;
        cin >> val >> al >> bob;
        if(al == 1 && bob == 1) {
            a.push_back(val);
        } else if(al == 1) {
            b.push_back(val);
        } else if(bob == 1) {
            c.push_back(val);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    if(a.size() + b.size() < k || a.size() + c.size() < k) {
        cout << -1;
        return 0;
    }
    ll ans = 2000000000000ll;
    ll now = 0;
    int nowb = min((int)b.size() - 1, k - 1);
    int nowc = min((int)c.size() - 1, k - 1);
    for(int i = 0; i <= nowb; i++) {
        now += b[i];
    }
    for(int i = 0; i <= nowc; i++) {
        now += c[i];
    }
    if(nowb == k - 1 && nowc == k - 1) {
        ans = now;
    }
    for(int i = 0; i < min(k, (int)a.size()); i++) {
        now += a[i];
        if(nowb != -1 && i + 1 + nowb >= k) {
            now -= b[nowb--];
        }
        if(nowc != -1 && i + 1 + nowc >= k) {
            now -= c[nowc--];
        }
        if(min(i + 2 + nowb, i + 2 + nowc) >= k) {
            ans = min(ans, now);
        }
    }
    cout << ans;
}