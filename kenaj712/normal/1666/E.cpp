#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int nax = 1e5 + 5;
int n, l;
int a[nax];
pii pref[nax];

bool can(int lo, int hi){
    pref[0] = mp(0, 0);
    for(int i=1;i<=n;i++){
        int from = pref[i - 1].st;
        int to = pref[i - 1].nd;
        from += lo;
        to += hi;
        if(to < a[i]) return false;
        if(i < n && from > a[i + 1]) return false;
        if(i == n && from > l) return false;
        from = max(from, a[i]);
        if(i < n) to = min(to, a[i + 1]);
        else to = min(to, l);
        assert(from <= to);
        pref[i] = mp(from, to);
    }
    return (pref[n].nd == l);
}

bool okL(int lo){
    return can(lo, 1e9);
}

int optHi(int lo){
    int L = lo;
    int R = 1e9;
    while(L + 1 < R){
        int mid = (L + R) / 2;
        if(can(lo, mid)) R = mid;
        else L = mid;
    }
    int odp = R;
    if(can(lo, L)) odp = L;
    return odp;
}

void solve(){
    cin >> l >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int L = 0;
    int R = 1e9;
    while(L + 1 < R){
        int mid = (L + R) / 2;
        if(okL(mid)) L = mid;
        else R = mid;
    }
    int optL = L;
    if(okL(R)) optL = R;
    int optH = optHi(optL);
    can(optL, optH);

    vector<int> ans;
    int pos = l;
    for(int i=n;i>=1;i--){
        int LOW = pref[i - 1].st;
        int HIGH = pref[i - 1].nd;
        int ruch = pos - HIGH;
        int potrzebuje = max(0, optL - ruch);
        ruch += potrzebuje;
        assert(ruch >= optL && ruch <= optH);
        ans.pb(ruch);
        pos -= ruch;
    }
    reverse(ans.begin(), ans.end());
    assert(pos == 0);
    for(int i=1;i<=n;i++){
        cout << pos << " " << pos + ans[i - 1] << "\n";
        pos += ans[i - 1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}