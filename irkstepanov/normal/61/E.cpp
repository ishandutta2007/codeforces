#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1e6 + 100;
int t[2 * nmax];
int n;

void upd(int pos) {
    for (pos += n; pos; pos >>= 1) {
        ++t[pos];
    }
}

int get(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans += t[l];
        }
        if (!(r & 1)) {
            ans += t[r];
        }
    }
    return ans;
}
 
int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> a(n);
    vector<pii> vct;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vct.pb({a[i], i});
    }

    sort(all(vct));
    vector<int> cnt1(n);
    for (int i = 0; i < n; ++i) {
        int pos = vct[i].second;
        cnt1[pos] = get(pos + 1, n - 1);
        upd(pos);
    }

    vector<int> cnt2(n);
    memset(t, 0, sizeof(t));
    for (int i = n - 1; i >= 0; --i) {
        int pos = vct[i].second;
        cnt2[pos] = get(0, pos - 1);
        upd(pos);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ll(cnt1[i]) * cnt2[i];
    }
    cout << ans << "\n";

}