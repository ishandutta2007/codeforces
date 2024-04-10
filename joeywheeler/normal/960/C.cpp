#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main() {
    ll x, d;
    scanf("%lld %lld", &x, &d);
    vector<ll> res;
    ll c = 1;
    for (int i = 30; i; i--) {
        while ((1<<i)-1 <= x) {
            x -= (1<<i)-1;
            fo(j,0,i) res.push_back(c);
            c += 1e10;
        }
    }
    printf("%d\n", sz(res));
    for (ll x : res) printf("%lld ", x);
}