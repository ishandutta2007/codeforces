#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
priority_queue<pair<ll,int> > q;
ll h[100005], t[100005];
bool p[100005];

int main() {
    scanf("%d", &n);
    FO(i,1,n+1) {
        scanf("%lld", &h[i]);
    }
    n += 2;
    FO(i,0,n) {
        t[i] = h[i];
        q.push(make_pair(-t[i],i));
    }
    while (!q.empty()) {
        ll T; int i; tie(T,i) = q.top(); q.pop();
        if (p[i]) continue;
        if (i && t[i-1] > t[i]+1) {
            t[i-1] = t[i]+1;
            q.push(make_pair(-t[i-1],i-1));
        }
        if (i<n && t[i+1] > t[i]+1) {
            t[i+1] = t[i]+1;
            q.push(make_pair(-t[i+1],i+1));
        }
    }
    ll res = 0;
    FO(i,0,n) res = max(res,t[i]);
    printf("%lld\n", res);
}