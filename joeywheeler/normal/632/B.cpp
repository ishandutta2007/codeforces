#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll p[500005];
char s[500005];
int n;

ll sa[500005], sb[500005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", p+i);
    scanf(" %s", s);
    FO(i,0,n) {
        sa[i+1] = sa[i];
        sb[i+1] = sb[i];
        if (s[i] == 'A') sa[i+1] += p[i];
        else sb[i+1] += p[i];
    }
    ll res = 0;
    FO(i,0,n+1) {
        res = max(res, sa[i] + sb[n]-sb[i]);
        res = max(res, sb[i] + sa[n]-sa[i]);
    }
    printf("%lld\n", res);
}