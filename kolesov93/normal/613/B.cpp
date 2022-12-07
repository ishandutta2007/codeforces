#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const int N = 100111;
int aa[N];
ll s[N];

struct cell {
    ll x;
    int pos;
} a[N];

bool byx(const cell& A, const cell& B) {
    return A.x < B.x;
}
bool byid(const cell& A, const cell& B) {
    return A.pos < B.pos;
}

ll cost(int n, ll level) {
    if (a[n].x <= level) {
        return level * ll(n) - s[n];
    }
    if (a[1].x >= level) return 0;

    int l = 1, r = n;
    while (l < r) {
        int c = (l + r + 1) >> 1;
        if (a[c].x >= level) r = c - 1;
        else l = c;
    }
    return level * ll(l) - s[l];
}

int main() {
    int n;
    ll A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", aa + i);
        a[i].x = aa[i];
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1, byx);
    for (int i = 1; i <= n; ++i) {
        s[i] = a[i].x + s[i - 1];
    }

    int best = 0;
    ll minvalue = a[1].x;
    ll ans = a[1].x * cm;
    for (int got = 0; got <= n; ++got) {
        ll have = m - (A * got - (s[n] - s[n - got]));       
        if (have < 0) break;
        
        ll llevel = a[1].x, rlevel = A;
        while (llevel < rlevel) {
            ll mid = (llevel + rlevel + 1) >> 1;
            if (cost(n - got, mid) <= have) llevel = mid;
            else rlevel = mid - 1;
        }

        ll value = cf * ll(got) + cm * llevel;
        if (ans <= value) {
            ans = value;
            best = got;
            minvalue = llevel;
        }
    }

    for (int i = 1; i <= n; ++i) {
        a[i].x = max(a[i].x, minvalue);
    }
    for (int i = 0; i < best; ++i) {
        a[n - i].x = A;
    }
    sort(a + 1, a + n + 1, byid);
   
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", int(a[i].x));
    }
    cout << endl;

    return 0;
}