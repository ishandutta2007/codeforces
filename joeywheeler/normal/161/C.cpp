#include <cstdio>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll first(ll a, ll b, ll c, ll d) {
    // first num in [a,b] = c mod d
    ll na = (a/d - 2) * d + c;
    while (na < a) na += d;
    return na > b ? -1 : na;
}

ll last(ll a, ll b, ll c, ll d) {
    // last num in [a,b] = c mod d
    ll nb = (b/d + 2) * d + c;
    while (nb > b) nb -= d;
    return nb < a ? -1 : nb;
}

int main() {
    int L0, R0, L1, R1;
    scanf("%d %d %d %d", &L0, &R0, &L1, &R1);
    ll l0=L0, r0=R0, l1=L1, r1=R1;
    ll res = 0;
    FO(i,0,31) {
        ll d = 1ll<<(i+1);
        ll dd = d/2;
        ll a0 = first(l0, r0, dd, d);
        ll b0 = last(l0, r0, dd, d);
        ll a1 = first(l1, r1, dd, d);
        ll b1 = last(l1, r1, dd, d);

        if (a0 == -1 || a1 == -1) continue;

        if ((b0-a0)/d >= 2) {
            a0 = b0 = a0+d;
        }
        if ((b1-a1)/d >= 2) {
            a1 = b1 = a1+d;
        }
        ll I[2] = {a0, b0};
        ll J[2] = {a1, b1};
        FO(i,0,2) FO(j,0,2) {
            res = max(res, 1 + min(J[j]-l1,min(I[i]-l0,dd-1)) + min(r1-J[j],min(r0-I[i],dd-1)));
        }
    }
    printf("%d\n", int(res));
}