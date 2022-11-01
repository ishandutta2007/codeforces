#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

const int N = 100005;
ll v[N];
pair<int,ll> cache[N*10+5];

pair<int,ll> calcbest(ll e) {
    if (e == 1) return make_pair(0, 0);
    if (e < N*10 && cache[e].first) return cache[e];

    int i = lower_bound(v,v+N,e)-v-1;
    ll a1 = e-v[i];
    ll a2 = -1;
    if (i >= 2) {
        a2 = v[i]-v[i-1];
    }

    pair<int,ll> res = {0, 0};
    if (a1 >= 1) {
        auto p = calcbest(a1);
        p.first++;
        p.second += v[i];
        res = max(res, p);
    }
    if (a2 >= 1) {
        auto p = calcbest(a2);
        p.first++;
        p.second += v[i-1];
        res = max(res, p);
    }

    if (e < N*10) cache[e] = res;
    return res;
}

ll m;
ll e;
ll os, oe; // (os,oe) -> (0,e)
int c = 0;

int main() {
    scanf(" %lld", &m);
    FO(i,0,N) v[i] = 1ll*i*i*i;
    pair<int,ll> res = calcbest(m+1);
    printf("%d %lld\n", res.first, res.second);
}