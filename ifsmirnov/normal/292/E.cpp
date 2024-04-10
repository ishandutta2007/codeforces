#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 100500;

struct node 
{
    int l, r;
    int lbl;
    node *L, *R;
    int x;
    node(int lq, int rq) {
        l = lq, r = rq;
        lbl = -1;
        x = -1;
        if (l == r) {
            L = R = NULL;
        }
        else {
            L = new node(l, (l+r)/2);
            R = new node((l+r)/2+1, r);
        }
    }
    void push() {
        if (lbl != -1) {
            if (l == r)
                x = lbl;
            else
                L->lbl = R->lbl = lbl;
            lbl = -1;
        }
    }
    int get(int i) {
        push();
        if (l == r)
            return x;
        else if (i <= (l+r)/2)
            return L->get(i);
        else
            return R->get(i);
    }
    void paint(int lq, int rq, int val) {
        push();
        if (lq <= l && rq >= r) {
            lbl = val;
        }
        else if (lq > r || rq < l) {
        }
        else {
            L->paint(lq, rq, val);
            R->paint(lq, rq, val);
        }
    }
};


int n, m;
int a[maxn], b[maxn], d[maxn];

void scan()
{
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) scanf("%d", &b[i]);
}

void solve()
{
    node *t = new node(0, n-1);
    forn(i, m) {
        //forn(j, n) cout << t->get(j) << " "; cout << endl;
        int q;
        scanf("%d", &q);
        if (q == 1) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            --l, --r;
            d[i] = r-l;
            t->paint(r, r+k-1, i);
        }
        else {
            int x;
            scanf("%d", &x);
            --x;
            int p = t->get(x);
            if (p == -1)
                printf("%d\n", b[x]);
            else
                printf("%d\n", a[x-d[p]]); 
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}