#include <bits/stdc++.h>

using namespace std;

inline void GetInt(int& x);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 300500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;
const int need_len = 31;

struct node {
    int node_size;
    node *l, *r;
    node() : l(nullptr), r(nullptr), node_size(0) {}
    node(int x) : l(nullptr), r(nullptr), node_size(x) {}
    node(node* L, node* R) {
        l = L;
        r = R;
        node_size = (L ? L -> node_size : 0) + (R ? R -> node_size : 0);
    }
};

typedef node * pnode;

inline int GetSize(pnode T) {
    return T ? T -> node_size : 0;
}

vector <int> cur_c;

inline void Recalc(int x) {
    cur_c.clear();
    while (x) {
        cur_c.pb(x & 1);
        x >>= 1;
    }
    while (cur_c.size() != need_len)
        cur_c.pb(0);
}

inline pnode Insert(pnode T, int pos) {
    if (pos < 0) {
        if (T) {
            ++T -> node_size;
            return T;
        }
        T = new node(1);
        return T;
    }
    if (cur_c[pos]) {
        if (!T)
            T = new node();
        T -> r = Insert(T -> r, pos - 1);
        T -> node_size = GetSize(T -> l) + GetSize(T -> r);
        return T;
    }
    if (!T)
        T = new node();
    T -> l = Insert(T -> l, pos - 1);
    T -> node_size = GetSize(T -> l) + GetSize(T -> r);
    return T;
}

inline void Add(pnode T, int x) {
    Recalc(x);
    Insert(T, cur_c.size() - 1);
}

inline int Solve(pnode T, int x) {
    Recalc(x);
    // pnode L = roots[l - 1];
    // pnode R = roots[r];
    --T -> node_size;
    int ans = 0;
    for (int i = cur_c.size() - 1; i >= 0; --i) {
        if (!cur_c[i]) {
            if (GetSize(T -> l)) {
                T = T -> l;
                --T -> node_size;
            } else {
                ans += 1 << i;
                T = T -> r;
                --T -> node_size;
            }
            continue;
        }

        if (GetSize(T -> r)) {
            T = T -> r;
            --T -> node_size;
        } else {
            ans += 1 << i;
            T = T -> l;
            --T -> node_size;
        }
    }
    return ans;
}

int a[maxn];
int b[maxn];
pnode T = new node();

int main()
{
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &b[i]);
        Add(T, b[i]);
    }

    for (int i = 0; i < n; ++i) {
        int x = 
        printf ("%d\n", Solve(T, a[i]));
    }
    // GetInt(n);
    // GetInt(q);
    // for (int i = 1; i <= n; ++i)
    //     GetInt(a[i]);
    // roots[0] = new node();
    // for (int i = 1; i <= n; ++i)
    //     roots[i] = Add(roots[i - 1], a[i]);

    // while (q--) {
    //     int l, r, x;
    //     GetInt(l);
    //     GetInt(r);
    //     GetInt(x);
    //     printf("%d\n", Solve(l, r, x));
    // }
    return 0;
}