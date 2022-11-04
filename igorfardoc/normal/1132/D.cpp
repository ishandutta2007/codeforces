#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define maxn 200000
#define time time1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> s1;
ll a[maxn];
ll a1[maxn];
int b[maxn];
int n, k;

bool check(ll mid) {
    for(int i = 0; i < n; i++) {
        a1[i] = a[i];
    }
    bool ok = true;
    vvi time(n);
    auto s = s1;
    for(int i = 0; i < k; i++) {
        auto p = s.top();
        int id = p.second;
        if(a1[id] / b[id] >= k - 1) break;
        time[id].push_back(i);
        a1[id] += mid;
        s.pop();
        s.push({a1[id] / b[id], id});
    }
    for(int i = 0; i < n; i++) {
        time[i].push_back(k - 1);
        ll now = a[i];
        int bef = -1;
        for(const auto& el : time[i]) {
            //cout << now << ' ' << i << ' ' << el << ' ' << mid << endl;
            int minus = el - bef - 1;
            now -= (ll)minus * b[i];
            if(now < 0) {
                ok = false;
                break;
            }
            now -= b[i] - mid;
            /*if(now < 0) {
                ok = false;
                break;
            }*/
            bef = el;
        }
        if(!ok) break;
    }
    return ok;
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        s1.push({a[i] / b[i], i});
    }
    ll l = -1;
    ll r = 2000000000000ll;
    if(!check(r)) {
        cout << -1;
        return 0;
    }
    while(r - l > 1) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}