#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int l[100005], r[100005];
ll s[100005];
int n;
int p[100005];
ll rs[100005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", &s[i]);
    FO(i,0,n) l[i] = r[i] = -1;
    FO(i,0,n) scanf("%d", p+i), p[i]--;
    reverse(p,p+n);
    ll ans = 0;
    FO(I,0,n) {
        rs[n-I-1] = ans;
        int i = p[I];
        int lft = i == 0 || l[i-1] == -1 ? i : l[i-1];
        int rgt = i == n-1 || r[i+1] == -1 ? i : r[i+1];
        ll sm = s[i];
        if (lft != i) sm += s[lft];
        if (rgt != i) sm += s[rgt];

        s[lft] = s[rgt] = sm;
        r[lft] = rgt;
        l[rgt] = lft;

        ans = max(ans, sm);
    }
    FO(i,0,n) printf("%lld\n", rs[i]);
}