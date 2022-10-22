#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool comp(pii a, pii b) {
    return a.vb < b.vb;
}
pii song[303030];
ll sumi[303030];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i=1; i<=n; i++) {
        scanf("%d%d", &song[i].va, &song[i].vb);

    }

    sort(song+1, song+1+n, comp);

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i=n; i>n-k; i--) {
        sumi[i] = sumi[i+1] + song[i].va;
        pq.push(song[i].va);
    }
    for (int i=n-k; i>0; i--) {
        if (pq.top() < song[i].va) {
            sumi[i] = sumi[i+1] - pq.top() + song[i].va;
            pq.pop();
            pq.push(song[i].va);
        }
        else {
            sumi[i] = sumi[i+1];
        }
    }

    ll maxi = 0;
    for (int i=1; i<=n; i++) {
        maxi = max(maxi, sumi[i]*song[i].vb);
    }

    printf("%lld", maxi);
}