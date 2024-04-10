#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;

bool cmp(pair<p,int> A, pair<p,int> B) {
    p a = A.first; p b = B.first;
    return b.second != a.second ? a.second < b.second : a.first > b.first;
}

ll l[400005], r[400005];
pair<p,int> x[400005];
pair<ll,int> b[400005];
int n, m;
int ans[400005];

set<pair<ll,int> > s;

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        scanf("%lld %lld", l+i, r+i);
    }
    FO(i,0,m) {
        scanf("%lld", &b[i].first);
        b[i].second = i;
    }
    sort(b,b+m);
    FO(i,0,n-1) {
        x[i].first = make_pair(l[i+1]-r[i],r[i+1]-l[i]);
        //printf("%lld %lld\n", x[i].first.first, x[i].first.second);
        x[i].second = i;
    }
    sort(x,x+n-1,cmp);
    int j = 0;
    FO(Z,0,n-1) {
        auto e = x[Z];
        p y = e.first;
        int i = e.second;

        while (j < m && b[j].first <= y.second) s.insert(b[j++]);
        //printf("j=%d\n", j);
        auto it = s.lower_bound(make_pair(y.first, -1));
        if (it == s.end()) {
            printf("No\n");
            return 0;
        }
        ans[i] = it->second;
        s.erase(it);
    }
    printf("Yes\n");
    FO(i,0,n-1) printf("%d%c", 1+ans[i], " \n"[i+1==n-1]);
}