#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n, x;
int a[1000500];
int l[1000005], r[1000050];
int maxi[1000050], mini[1000050];
ll ans = 0;
int lower;
int upper;

bool sorted() {
    int now = -1;
    for(int i = 1; i <= n; i++) {
        if(lower <= a[i] && a[i] <= upper) continue;
        if(a[i] < now) return false;
        now = a[i];
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= 1e6; i++) {
        l[i] = n + 1;
        r[i] = 0;
        maxi[i] = -1;
        mini[i] = x + 1;
    }
    for(int i = 1; i <= n; i++) {
        maxi[i] = max(maxi[i-1], a[i]);
        mini[i] = min(mini[i - 1], a[i]);
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    lower = 1;
    ll ok = x;
    ll ng = 0;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        upper = mid;
        if(sorted()) ok = mid;
        else ng = mid;
    }
    upper = ok;
    ans += (x - upper + 1);
    cerr << 1 << " " << ok << endl;
    int mostl = n + 1;
    int mostr = 0;
    while(lower < x) {
        if(l[lower] < mostr) upper = x + 1;
        mostl = min(mostl, l[lower]);
        mostr = max(mostr, r[lower]);
        if(r[lower] >= 1) upper = max(upper, maxi[r[lower] - 1]);
        lower++;
        upper = max(upper, lower);
        //cerr << lower << " " << upper << endl;
        ans += (x - upper + 1);
    }
    cout << ans << endl;
    return 0;
}