#include<bits/stdc++.h>
#define inf 2000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


vi a;
bool ok = true;

int get_sz(vi a) {
    int n = a.size();
    if(n == 0) return 0;
    vi d(n + 1, inf);
    d[0] = -inf;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int id1 = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        res = max(res, id1);
        d[id1] = a[i];
    }
    return res;
}

int doit(int l, int r) {
    //cout << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << endl;
    if(!ok) {
        return 0;
    }
    if(a[l] > a[r]) {
        ok = false;
        return 0;
    }
    int mn = a[l];
    int mx = a[r];
    vi now;
    int res = 0;
    for(int i = l + 1; i < r; i++) {
        if(a[i] > mx || a[i] < mn) {
            ++res;
        } else {
            now.push_back(a[i]);
        }
    }
    return res + now.size() - get_sz(now);
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
    int n, k;
    cin >> n >> k;
    a.resize(n + 2);
    a[0] = -1000000001;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    n += 2;
    a[n - 1] = 1000000001;
    vi b(k + 2);
    b[0] = 0;
    for(int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    k += 2;
    b[k - 1] = n - 1;
    int ans = 0;
    int start = 0;
    int now = 1;
    for(int i = 1; i < n; i++) {
        if(b[now] == i) {
            ans += doit(start, i);
            start = i;
            ++now;
        }
    }
    if(!ok) {
        cout << -1;
    } else {
        cout << ans;
    }
}