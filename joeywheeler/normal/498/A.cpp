#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
typedef complex<ll> p;

ll cross(p a, p b) {return real(conj(a)*b);}

bool is(p a, p b, p c, p d) {
    return cross(c-a,b-a) * cross(d-a,b-a) < 0 &&
        cross(a-c,d-c) * cross(b-c,d-c) < 0;
}

p a, av;

int main() {
    scanf("%lld %lld", &a.real(), &a.imag());
    scanf("%lld %lld", &av.real(), &av.imag());
    int n; scanf("%d", &n);
    int res = 0;
    FO(Z,0,n) {
        ll b, c, d; scanf("%lld %lld %lld", &b, &c, &d);
        ll e0 = b*real(a) + c*imag(a) + d;
        ll e1 = b*real(av) + c*imag(av) + d;
        if (e0 < 0 && e1 > 0 || e0 > 0 && e1 < 0) res++;
    }
    printf("%d\n", res);
}