#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

unsigned int pw(unsigned int a, unsigned int b) {
    unsigned int res = 1;
    while (b) {
        if (b&1) res = res*a;
        a = a*a;
        b /= 2;
    }
    return res;
}

unsigned int inv(unsigned int x) {
    assert(x%2 == 1);
    unsigned int res = pw(x, (1u<<31) - 1);
    assert(res*x == 1);
    return res;
}

unsigned int c(int n, int k)
{
    unsigned int num=1, den=1, fct2 = 0;
    FO(i,1,k+1) {
        int tmp = __builtin_ctz(i);
        fct2 -= tmp;
        den *= i>>tmp;

        tmp = __builtin_ctz(n-i+1);
        fct2 += tmp;
        num *= (n+1-i)>>tmp;
    }
    return num*inv(den) << fct2;
}

int n, p, q;
unsigned int cf[150];

int main() {
    scanf("%d%d%d", &n, &p, &q);
    p = min(p, n-1);
    FO(i,0,p+1) cf[i] = c(n,i);
    unsigned int ans = 0;
    FO(i,1,q+1) {
        unsigned int d = i;
        unsigned int cp = 1;
        unsigned int res = 0;
        FO(j,0,p+1) {
            res += cf[j] * cp;
            cp *= d;
        }
        ans ^= res * i;
    }
    printf("%u\n", ans);
}