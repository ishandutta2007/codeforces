#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;
int n, m, arr[505];

vector<ll> calc(int l, int r) {
    int mn=n+1, mnp;

    if (l==r) {
        vector<ll> ret;
        ret.push_back(0);
        ret.push_back(1);
        return ret;
    }
    if (l>r) {
        vector<ll> ret;
        ret.push_back(1);
        return ret;
    }

    for (int i=l; i<=r; i++) {
        if (mn > arr[i]) {
            mn = arr[i];
            mnp = i;
        }
    }

    vector<ll> a = calc(l, mnp-1);
    vector<ll> b = calc(mnp+1, r);

//    cout << l << ' ' << r << ": ";
//    for (int i=0; i<a.size(); i++) cout << a[i] << ' ';
//    cout << '\n';
//
//    cout << l << ' ' << r << ": ";
//    for (int j=0; j<b.size(); j++) cout << b[j] << ' ';
//    cout << '\n';

    vector<ll> ret(r-l+2);
    int tmp;

    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            for (int k=1; k<=i+j+1; k++) {

                if (k<=min(i, j)+1) tmp = k;
                if (k>min(i, j)+1 && k<=max(i, j)) tmp = min(i, j)+1;
                if (k>max(i, j)) tmp = i+j+2-k;

                ret[k] = (ret[k] + a[i]*b[j]%mod*tmp%mod)%mod;

            }
        }
    }

    return ret;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];

    vector<ll> ansv = calc(0, n-1);

    ll ans = 0;

    for (int i=0; i<ansv.size(); i++) {
        ans = (ans+ansv[i])%mod;
    }

    cout << ans;
}