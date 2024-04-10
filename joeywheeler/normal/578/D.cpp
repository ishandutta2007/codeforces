#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

char s[100005];
ll n, m;

int f[100005];

int main() {
    scanf("%lld %lld", &n, &m);
    scanf(" %s", s);
    ll res = n * (m-1);
    FO(i,1,n) {
        if (s[i] != s[i-1]) {
            res += i * (m-1);
        }
    }
    FO(i,0,n-1) {
        if (s[i] != s[i+1]) {
            res += (n-1-i) * (m-1);
        }
    }
    FO(i,0,n) {
        if (i < 2 || s[i] != s[i-2]) f[i] = 1;
        else f[i] = f[i-2]+1;
        if (i>0) {
            int len = min(2*f[i],2*f[i-1]+1);
            if (s[i] != s[i-1] && len >= 2) res -= len-1;
        }
    }
    printf("%lld\n", res);
}