#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 111111
int n;
ll a[N];
int p[N];
int deg[N];
bool good[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d", &p[i]);
        deg[--p[i]]++;
    }
    vector<int> queue;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) {
            good[i] = true;
            queue.push_back(i);
        }
    }
    ll target = 0;
    vector<ll> goods;
    map<ll,int> bads;
    for (int f = 0; f < queue.size(); f++) {
        int i = queue[f];
        if (good[i]) {
            goods.push_back(a[i]);
            target ^= a[i];
        } else {
            bads[a[i]]++;
        }
        if (!--deg[p[i]]) {
            good[p[i]] = !good[i];
            queue.push_back(p[i]);
        }
    }
    ll ans = 0;
    for (ll v : goods) {
        ans += bads[target ^ v];
    }
    if (target == 0) {
        ll goodc = goods.size();
        ll badc = n - goodc;
        ans += goodc * (goodc - 1) / 2;
        ans += badc * (badc - 1) / 2;
    }
    printf("%lld\n", ans);
}