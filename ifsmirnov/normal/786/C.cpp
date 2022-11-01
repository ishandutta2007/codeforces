#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 100500;

struct node;
node* newNode();

struct node {
    int l, r;
    node *L, *R;
    int s;
    node(int l, int r) : l(l), r(r), s(0) {
        if (l+1 == r) {
            L = R = NULL;
        } else {
            int m = (l+r)/2;
            L = new node(l, m);
            R = new node(m, r);
        }
    }

    node* clone() const {
        node *t = newNode();
        *t = *this;
        return t;
    }

    node* add(int i, int d) {
        node *t = clone();
        t->s += d;
        if (l+1 < r) {
            if (i < (l+r)/2) {
                t->L = L->add(i, d);
            } else {
                t->R = R->add(i, d);
            }
        }
        return t;
    }

    int go(int mx) {
        if (s <= mx) return r;
        if (l+1 == r) return l;
        if (L->s <= mx) {
            mx -= L->s;
            return R->go(mx);
        } else {
            return L->go(mx);
        }
    }

    node(){}
};

node buf[6000000];
int ptr;
node* newNode() {
    return buf + ptr++;
}

int n;
int a[maxn];
int lst[maxn], nxt[maxn];
node *t[maxn];

void scan() {
    cin >> n;
    forn(i, n) cin >> a[i];
}

void build() {
    memset(lst, -1, sizeof lst);
    memset(nxt, -1, sizeof nxt);
    t[0] = new node(0, n);
    forn(i, n) {
        int x = a[i];
        if (lst[x] == -1) {
            t[0] = t[0]->add(i, 1);
        } else {
            nxt[lst[x]] = i;
        }
        lst[x] = i;
    }
    forn(i, n) if (i) {
        t[i] = t[i-1]->add(i-1, -1);
        if (nxt[i-1] != -1) t[i] = t[i]->add(nxt[i-1], 1);
    }
}

void solve() {
    fore(k, 1, n) {
        int res = 0;
        int i = 0;
        while (i < n) {
            ++res;
            i = t[i]->go(k);
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    scan();
    build();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}