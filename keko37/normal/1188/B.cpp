#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;

llint n, p, k, sol;
llint a[MAXN];
map <int, vector <int> > mp;

llint sq (llint x) {
    return x * x % p;
}

llint f (llint x) {
    llint res = sq(sq(x)) - k * x;
    res = (res % p + p) % p;
    return res;
}

bool ok (llint x, llint y) {
    llint res = (sq(x) + sq(y)) % p;
    res = res * (x + y) % p;
    return res == k;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        vector <int> v = mp[f(a[i])];
        for (int j=0; j<v.size(); j++) {
            if (ok(a[i], v[j])) sol++;
        }
        mp[f(a[i])].push_back(a[i]);
    }
    cout << sol;
    return 0;
}