#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N = 2e5 + 9;
set<int>t[N << 2];
void chmx(int &ewq, int qwq) {
    (ewq < qwq) ? (ewq = qwq) : (0);
}
void chmn(int &ewq, int qwq) {
    (ewq > qwq) ? (ewq = qwq) : (0);
}
inline int read() {
    int f = 0, ewq = 0;
    char ch = getchar();

    while (!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }

    while (isdigit(ch)) {
        ewq = ewq * 10 + ch - '0';
        ch = getchar();
    }

    return f ? -ewq : ewq;
}
struct tree {
#define ls (p<<1)
#define rs (p<<1|1)
    void add(int p, int l, int r, int ewq, int v) {
        t[p].insert(v);

        if (l == r) {
            return;
        }

        int mid = (l + r) >> 1;

        if (mid >= ewq)
            add(ls, l, mid, ewq, v);
        else
            add(rs, mid + 1, r, ewq, v);
    }
    int get(int p, int l, int r, int nl, int nr, int v) {
        if (nl <= l && r <= nr) {
            auto it = t[p].lower_bound(v);
            return it == t[p].end() ? INT_MAX : *it;
        }

        int mid = (l + r) >> 1, res = 2e9;

        if (mid >= nl)
            chmn(res, get(ls, l, mid, nl, nr, v));

        if (mid < nr)
            chmn(res, get(rs, mid + 1, r, nl, nr, v));

        return res;
    }
} T;

int a[N], m, n;
set<int>S;
int main() {
    n = read(), m = read();
    S.insert(0);
    rep(i, n)S.insert(i);
    S.insert(n + 1);

    while (m--) {
        int op, ewq, qwq, fz;
        op = read(), ewq = read();

        if (op) {
            auto it = S.find(ewq);

            if (it != S.end()) {
                int l = *prev(it) + 1, r = *next(it) - 1;

                if (T.get(1, 1, n, l, ewq, ewq) <= r)
                    puts("YES");
                else
                    puts("N/A");
            } else
                puts("NO");
        } else {
            qwq = read(), fz = read();

            if (fz)
                T.add(1, 1, n, ewq, qwq);
            else {
                auto it = S.lower_bound(ewq);

                while (1) {
                    if (it != S.end() && *it <= qwq)
                        it = S.erase(it);
                    else
                        break;
                }
            }
        }
    }

    return 0;
}