#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
int n;
ll m, s, d;
ll a[200005];
set<pair<ll,ll> > land;

char buf[100];

int main() {
    scanf("%d %lld %lld %lld", &n, &m, &s, &d);
    FO(i,0,n) {
        scanf("%lld", &a[i]);
    }
    sort(a,a+n);
    FO(i,0,n) {
        if (a[i+1]-a[i]-2 >= s) land.insert(make_pair(a[i]+1,a[i+1]-1));
    }
    land.insert(make_pair(a[n-1]+1,m));
    ll pos = a[0]-1;
    if (pos < s) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    vector<string> res;
    if (pos != 0) {
        sprintf(buf, "RUN %lld\n", pos);
        res.emplace_back(buf);
    }
    while (pos != m) { //jmp from pos to somewhere <= pos+d
        auto it = land.upper_bound(make_pair(pos+d,1ll<<60));
        if (it == land.begin()) {
            printf("IMPOSSIBLE\n");
            return 0;
        } else {
            --it;
            if (it->first <= pos) {
                printf("IMPOSSIBLE\n");
                return 0;
            } else {
                sprintf(buf, "JUMP %lld\n", it->first-pos);
                res.emplace_back(buf);
                if (it->second != it->first) {
                    sprintf(buf, "RUN %lld\n", it->second-it->first);
                    res.emplace_back(buf);
                }
                pos = it->second;
            }
        }
    }
    for (string s : res) printf("%s", s.c_str());
}