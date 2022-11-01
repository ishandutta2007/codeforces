#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct RT {
    typedef pair<int,int> T;

    T v[8000005];
    static constexpr T IDENTITY = {0,0};
    T op(T a, T b) {
        int x = min(a.second,b.first);
        return T(a.first+b.first-x, a.second+b.second-x);
    }

    T q(int i, int rs, int re, int qs, int qe) {
        if (rs==qs && re==qe) return v[i];
        else {
            int md=(rs+re)/2;
            T r = IDENTITY;
            if (qs<md) r = op(r, q(2*i+1, rs, md, qs, min(qe,md)));
            if (qe>md) r = op(r, q(2*i+2, md, re, max(qs,md), qe));
            return r;
        }
    }

    void u(int i, int rs, int re, int qi, T qv) {
        if (rs+1==re) v[i] = qv;
        else {
            int md=(rs+re)/2;
            if (qi<md) u(2*i+1, rs, md, qi, qv);
            else u(2*i+2, md, re, qi, qv);
            v[i] = op(v[2*i+1], v[2*i+2]);
        }
    }
} r;

char s[2000005];
ll md[2] = {1000000007, 1000000009};
ll h[2000005][2];
ll hs[2000005][2];
int n;

ll hsh(int i, int j, int k) {
    return ((hs[j][k]-hs[i][k]+md[k]) * h[2*n-i][k]) % md[k];
}

bool l(int i, int j) {
    int S = 0, e = n, b = 0;
    while (S <= e) {
        int mid = (S+e)/2;
        bool eq = true;
        FO(k,0,2) if (hsh(i,i+mid,k) != hsh(j,j+mid,k)) eq = false;
        if (eq) {
            b = mid;
            S = mid+1;
        } else e = mid-1;
    }
    return s[i+b] < s[j+b];
}

int main() {
    FO(i,0,2) h[0][i] = 1;
    FO(i,1,2000005) FO(j,0,2) h[i][j] = (h[i-1][j] * 137) % md[j];
    scanf(" %s", s); n = strlen(s);
    FO(i,0,n) s[i+n] = s[i];

    FO(i,1,2*n+1) FO(j,0,2) hs[i][j] = (hs[i-1][j] + h[i-1][j] * s[i-1]) % md[j];

    FO(i,0,2*n) if (s[i] == ')') {
        r.u(0, 0, 2*n, i, {1,0});
    } else {
        r.u(0, 0, 2*n, i, {0,1});
    }
    pair<int,int> e;
    int b = -1;
    FO(i,0,n) {
        pair<int,int> a = r.q(0, 0, 2*n, i, i+n);
        if (a.first == 0 || a.second == 0) {
            e = a;
            if (b == -1 || l(i, b)) b = i;
        }
    }
    FO(i,0,e.first) printf("(");
    FO(i,b,b+n) printf("%c", s[i]);
    FO(i,0,e.second) printf(")");
    printf("\n");
}