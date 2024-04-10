#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

struct rng {
    int s, e;
    bool operator<(const rng &oth) const {
        return s < oth.s;
    }
} rs[234];
bool is(rng a, rng b) {
//    printf("%d %d %d %d\n", a.s, a.e, b.s, b.e);
    if (a.s <= b.e && a.e >= b.s) return 1;
    return 0;
}
int n, s, d;
int main() {
    scanf("%d", &n);
    fo(i,0,n) {
        if (i > 0) printf("%d %d\n", rs[i-1].s, rs[i-1].e);
        sort(rs, rs+i);
        scanf("%d %d", &s, &d);
        char g = 1;
        rng tr;
        tr.s = s; tr.e = s + d - 1;
        fo(j,0,i) if (is(tr, rs[j])) g = 0;
        if (g == 1) {
            rs[i] = tr; continue;
        }
        tr.s = 1; tr.e = d;
        if (!i || !is(tr, rs[0])) {
            rs[i] = tr; continue;
        }
        fo(j,0,i) {
            tr.s = rs[j].e + 1;
            tr.e = tr.s + d - 1;
            if (j == i-1 || !is(tr, rs[j+1])) {
                rs[i] = tr; break;
            }
        }
    }
    printf("%d %d\n", rs[n-1].s, rs[n-1].e);

    return 0;
}