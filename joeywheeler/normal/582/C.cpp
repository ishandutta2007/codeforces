#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
int a[400010];
int m[400010];
int t[400010];
vector<int> v[400010];
int c[400010];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,0,n) a[i+n] = a[i];
    FO(s,1,n) {
        v[__gcd(s,n)].push_back(s);
    }
    ll res = 0;
    FO(s,1,n) if (n%s == 0) {
        for (int x : v[s]) c[x] = 1;
        FO(i,1,2*n+5) c[i] += c[i-1];
        FO(i,0,s) {
            m[i] = 0;
            for (int j = i; j < n; j += s) m[i] = max(m[i], a[j]);
        }
        FO(i,s,2*n) m[i] = m[i-s];
        for (int i = 2*n-1; i >= 0; i--) {
            t[i] = 0;
            if (a[i] >= m[i]) t[i] = 1 + t[i+1];
            if (i < n) {
                res += c[t[i]];
            }
        }
        //FO(i,0,2*n) {
            //printf("%d ", t[i]);
        //}
        //printf("\n");
        FO(i,0,2*n+5) c[i] = 0;
    }
    printf("%lld\n", res);
}