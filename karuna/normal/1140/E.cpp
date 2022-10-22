#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 998244353;

int n, k;
vector<int> even;
vector<int> odd;
ll diff(int len);

ll same(int len) {
    if (len == 0) {
        return 0;
    }

    if (len%2 == 1) {
        ll a1 = same(len/2);
        ll a2 = diff(len/2);
        return (a1*a1%mod + (k-1)*(a2*a2%mod)%mod)%mod;
    }
    else {
        return (k-1)*diff(len-1)%mod;
    }
}
ll diff(int len) {
    if (len == 0) {
        return 1;
    }

    if (len%2 == 1) {
        ll a1 = same(len/2);
        ll a2 = diff(len/2);
        return (2*(a1*a2%mod)%mod+(k-2)*(a2*a2%mod)%mod)%mod;

    }
    else {
        return (same(len-1)+(k-2)*diff(len-1)%mod)%mod;
    }

}
ll calc(vector<int> &v, int lo, int hi) {
    int len = hi-lo+1;

    if (lo == 0 && hi == v.size()-1) {
        if (len == 1) {
            return k;
        }
        else {
            return k*calc(v, lo+1, hi)%mod;
        }
    }

    if (lo == 0 || hi == v.size()-1) {
        return ((k-1)*diff(len-1)%mod + same(len-1))%mod;
    }

    if (v[lo-1] == v[hi+1]) {
        return same(len);
    }
    else {
        return diff(len);
    }
}
ll solve(vector<int> &v) {
    ll ret = 1;
    int lo = 0, hi = -1;

    for (int i=0; i<v.size()-1; i++) {
        if (v[i] == v[i+1] && v[i]!=-1) {
            return 0;
        }
    }

    for (int i=0; i<v.size(); i++) {
        if (v[i] == -1) {
            hi = i;
        }
        else {
            if (hi>=lo) {
                ret = (ret*calc(v, lo, hi))%mod;
            }
            hi = i;
            lo = i+1;
        }
    }

    if (lo<v.size()) {
        ret = (ret*calc(v, lo, hi))%mod;
    }

    return ret;
}
int main() {
    scanf("%d %d", &n, &k);

    int a;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a);
        if (i%2==1) {
            odd.push_back(a);
        }
        else {
            even.push_back(a);
        }
    }

    printf("%lld", solve(even)*solve(odd)%mod);
}