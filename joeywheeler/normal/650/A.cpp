#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

long long cs(vector<pair<ll,ll> > v) {
    sort(v.begin(),v.end());
    ll res = 0;
    int c = 1;
    FO(i,1,sz(v)) {
        if (v[i] == v[i-1]) {
            res += c;
            c++;
        } else {
            c = 1;
        }
    }
    return res;
}

ll x[200005];
ll y[200005];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld %lld", x+i, y+i);

    vector<pair<ll,ll> > v(n);
    FO(i,0,n) v[i] = make_pair(x[i],0);
    ll res = cs(v);
    FO(i,0,n) v[i] = make_pair(y[i],0);
    res += cs(v);
    FO(i,0,n) v[i] = make_pair(x[i],y[i]);
    res -= cs(v);
    printf("%lld\n", res);
}