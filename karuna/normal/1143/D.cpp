#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, k, a, b;
ll gcd(ll n, ll m) {
    if (n*m==0)
        return n+m;
    if (n<m)
        return gcd(m, n);
    return gcd(m, n%m);
}
int main() {
    scanf("%lld%lld", &n, &k);
    scanf("%lld%lld", &a, &b);

    vector<ll> v;
    v.push_back((a+b)%k);
    v.push_back((k+a-b)%k);
    v.push_back((k-a-b)%k);
    v.push_back((k-b+a)%k);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll maxi = 1;
    ll mini = 12938012938019;
    ll g;
    for (int i=0; i<n; i++) {
        for (int j=0; j<v.size(); j++) {
            g = gcd(i*k+v[j], n*k);
            maxi = max(maxi, g);
            mini = min(mini, g);
        }
    }
    printf("%lld %lld", n*k/maxi, n*k/mini);
}