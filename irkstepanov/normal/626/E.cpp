#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

vector<ll> pref;

ll sum(int l, int r)
{
    if (!l) {
        return pref[r];
    }
    return pref[r] - pref[l - 1];
}

struct answer
{
    int med;
    int len;
    bool odd;
    ll ch, zn;
};

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    cin >> n;

    vector<ll> a(n);
    pref.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    answer ans;
    ans.ch = 0, ans.zn = 1;
    /*for (int i = 1; i < n - 1; ++i) {
        ll ch = a[i - 1] - 2 * a[i] + a[n - 1];
        ll zn = 3;
        if (ans.ch * zn < ch * ans.zn) {
            ans.ch = ch;
            ans.zn = zn;
            ans.len = 3;
            ans.med = i;
            ans.odd = true;
        }
    }

    for (int i = 1; i < n - 2; ++i) {
        ll ch = a[i - 1] - 2 * a[i] - 2 * a[i + 1] + a[n - 1];
        ll zn = 4;
        if (ans.ch * zn < ch * ans.zn) {
            ans.ch = ch;
            ans.zn = zn;
            ans.len = 4;
            ans.med = i;
            ans.odd = false;
        }
    }*/

    for (int i = 1; i < n - 1; ++i) {
        int l = 1, r = min(i, n - i - 1) + 1;
        while (l != r - 1) {
            int mid = (l + r) >> 1;
            ll a1 = sum(i - mid, i) + sum(n - mid, n - 1);
            ll a2 = sum(i - (mid - 1), i) + sum(n - (mid - 1), n - 1);
            if (a1 * (2 * (ll)(mid) - 1) > a2 * (2 * (ll)(mid) + 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ll ch = sum(i - l, i) + sum(n - l, n - 1);
        ch -= a[i] * (2 * (ll)(l) + 1);
        ll zn = 2 * (ll)(l) + 1;
        if (ans.ch * zn < ch * ans.zn) {
            ans.ch = ch;
            ans.zn = zn;
            ans.len = l;
            ans.med = i;
            ans.odd = true;
        }
    }

    for (int i = 1; i < n - 2; ++i) {
        int l = 1, r = min(i, n - i - 2) + 1;
        while (l != r - 1) {
            int mid = (l + r) >> 1;
            ll a1 = sum(i - mid, i + 1) + sum(n - mid, n - 1);
            ll a2 = sum(i - (mid - 1), i + 1) + sum(n - (mid - 1), n - 1);
            if (a1 * (2 * (ll)(mid)) > a2 * (2 * (ll)(mid) + 2)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ll ch = sum(i - l, i + 1) + sum(n - l, n - 1);
        ch -= (a[i] + a[i + 1]) * ((ll)(l) + 1);
        ll zn = 2 * (ll)(l) + 2;
        if (ans.ch * zn < ch * ans.zn) {
            ans.ch = ch;
            ans.zn = zn;
            ans.len = l;
            ans.med = i;
            ans.odd = false;
        }
    }

    if (ans.ch == 0) {
        cout << "1\n";
        cout << a[0] << "\n";
        return 0;
    }

    if (ans.odd) {
        cout << ans.len * 2 + 1 << "\n";
        for (int i = ans.med - ans.len; i <= ans.med; ++i) {
            cout << a[i] << " ";
        }
        for (int i = n - ans.len; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    cout << ans.len * 2 + 2 << "\n";
    for (int i = ans.med - ans.len; i <= ans.med + 1; ++i) {
        cout << a[i] << " ";
    }
    for (int i = n - ans.len; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

}