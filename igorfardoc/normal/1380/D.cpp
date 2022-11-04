#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi a, b;
int x, k, y;
ll ans = 0;
bool ok = true;

void do_it(int l, int r, int left, int right) {
    int max1 = -1;
    for(int i = l; i <= r; i++) {
        max1 = max(max1, a[i]);
    }
    int len = r - l + 1;
    if(max1 < max(left, right)) {
        ans += (ll)(len % k) * y;
        if((ll)y * k < x) {
            ans += (ll)(len - len % k) * y;
        } else {
            ans += (ll)(len / k) * x;
        }
        return;
    }
    if(len < k) {
        ok = false;
        return;
    }
    int need = len % k;
    int can = 0;
    for(int i = l; i <= r; i++) {
        if(a[i] < left) {
            ++can;
        } else {
            break;
        }
    }
    for(int i = r; i >= l; i--) {
        if(a[i] < right) {
            ++can;
        } else {
            break;
        }
    }
    ans += (ll)need * y;
    can -= need;
    if(x < (ll)y * k) {
        ans += (ll)x * (len / k);
        return;
    }
    ans += (ll)y * (len - need - k);
    ans += x;
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
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    cin >> x >> k >> y;
    vi where(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        where[a[i]] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        --b[i];
    }
    if(m > n) {
        cout << -1;
        return 0;
    }
    vi pos(m);
    for(int i = 0; i < m; i++) {
        if(where[b[i]] == -1) {
            cout << -1;
            return 0;
        }
        pos[i] = where[b[i]];
        if(i != 0 && pos[i - 1] > pos[i]) {
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < m; i++) {
        if(i == 0) {
            if(pos[i] == 0) {
                continue;
            }
            do_it(0, pos[i] - 1, -1, a[pos[i]]);
            continue;
        }
        if(pos[i] > pos[i - 1] + 1) {
            do_it(pos[i - 1] + 1, pos[i] - 1, a[pos[i - 1]], a[pos[i]]);
        }
    }
    if(pos[m - 1] != n - 1) {
        do_it(pos[m - 1] + 1, n - 1, a[pos[m - 1]], -1);
    }
    if(!ok) {
        cout << -1;
        return 0;
    }
    cout << ans;
}