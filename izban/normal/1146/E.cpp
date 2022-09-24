#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

mt19937 rnd(clock());

const int INF = 1.01e9;


struct item {
    int key, prior;
    int orig;
    int f;
    item * l, * r;
    item() { }
    item (int key, int prior, int orig) : key(key), prior(prior), orig(orig), f(1), l(NULL), r(NULL) { }
};
typedef item * pitem;

const int N = 2.1e5;
item items[N];

void push(pitem t) {
    if (t && t->f == -1) {
        if (t->l) t->l->f *= -1;
        if (t->r) t->r->f *= -1;
        swap(t->l, t->r);
        t->key *= -1;
        t->f = 1;
    }
}

void split (pitem t, int key, pitem & l, pitem & r) {
    push(t);
    if (!t)
        l = r = NULL;
    else if (key <= t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
}

void merge (pitem & t, pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

pitem unite (pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt = 0, rt = 0;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

void print(pitem t) {
    if (!t) return;
    push(t);
    print(t->l);
//    cout << t->orig << "->" << t->key << " ";
    cout << t->key << " ";
    print(t->r);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        auto v = a;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        pitem t = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            pitem cur = &items[i];
            *cur = item(v[i], rnd(), v[i]);
            merge(t, t, cur);
        }

//        print(t); cout << endl;
        for (int i = 0; i < q; i++) {
            char c;
            int x;
            scanf(" %c%d", &c, &x);

            pitem t1 = 0, t2 = 0;
            if (c == '<') {
                split(t, x, t1, t2);
                if (t1) t1->f *= -1;
            } else {
                split(t, x + 1, t1, t2);
                if (t2) t2->f *= -1;
            }
//            print(t1); cout << endl;
//            print(t2); cout << endl;
            t = unite(t1, t2);
//            print(t); cout << endl;
        }
        map<int, int> mp;
        function<void(pitem)> go = [&](pitem cur) {
            if (cur == 0) return;
            push(cur);
            mp[cur->orig] = cur->key;
            go(cur->l);
            go(cur->r);
        };
        go(t);
        for (int &x : a) x = mp[x];

        for (int i= 0; i < n; i++) printf("%d%c", a[i], " \n"[i + 1 == n]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}