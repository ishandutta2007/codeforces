#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
int n;
ll m;
set<ll> s;

int main() {
    scanf("%d %lld", &n, &m);
    FO(i,0,n) {
        ll x; scanf("%lld", &x);
        s.insert(x);
    }
    vector<int> v;
    for (int i = 1; m >= i; i++) {
        if (!s.count(i)) {
            v.push_back(i);
            m -= i;
        }
    }
    printf("%d\n", sz(v));
    for (int x : v) printf("%d ", x);
    printf("\n");
}