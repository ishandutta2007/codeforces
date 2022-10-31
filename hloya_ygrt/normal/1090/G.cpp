#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;


//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 5;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

struct node {
    int len; // prefix that is closed
    int mn; // leftest pos of one
    node * l, * r;

    node() {
        len = 0;
        mn = inf;
        l = 0, r = 0;
    }
};

int getlen(node* v) { 
    if (!v) return 0;
    return v -> len;
}

int getmn(node* v) {
    if (!v) return inf;
    return v -> mn;
}

void upd(node* v) {
    v -> len = getlen(v->l) + getlen(v->r);
    v -> mn = min(getmn(v->l), getmn(v->r));
}

const int L = 0, R = (int)250000; 

node* root[maxn];

node* cpy(const node* v) {
    node* res = new node();
    if (!v) 
        return res;
    res -> len = v -> len;
    res -> mn = v -> mn;
    res -> l   = v -> l;
    res -> r   = v -> r;
    return res;
}

int attack[maxn], dead[maxn];
node* single, * ones;

void init_ones(node* v, int tl, int tr) {
    if (tl == tr) {
        v -> len = 1;
        v -> mn = tl;
        return;
    }
    int tm = (tl + tr) >> 1;
    v -> l = new node();
    v -> r = new node();
    init_ones(v -> l, tl, tm);
    init_ones(v -> r, tm + 1, tr);
    upd(v);
}

node* makeones(node* v, node* ones, int tl, int tr, int l, int r) {
    if (l > r) return v;
    assert(ones);

    if (l == tl && r == tr) {
        // rep v with cpy(ones)
        v = cpy(ones);
        return v;
    }
    
    v = cpy(v);

    int tm = (tl + tr) >> 1;

    v -> l = makeones(v -> l, ones -> l, tl, tm, l, min(r, tm));
    v -> r = makeones(v -> r, ones -> r, tm + 1, tr, max(l, tm + 1), r);

    upd(v);
    return v;
}

void init_single() {
    single = makeones(single, ones, L, R, 0, 0);
}

int findpos(node* v, int tl, int tr, int r) {
    if (tl == tr) {
        // don't call when there is no such mn
        assert(v -> mn == tl);
        assert(v -> len);
        assert(tl <= r);
        return tl;
    }
    
    int tm = (tl + tr) >> 1;
    if (getmn(v -> r) <= r)
        return findpos(v -> r, tm + 1, tr, r);
    else {
        return findpos(v -> l, tl, tm, r);
    }
}

node* setzero(node* v, int tl, int tr, int pos) {
    v = cpy(v);

    if (tl == tr) {
        v -> mn = inf;
        v -> len = 1; // make this procedure universal
        return v;
    }

    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        v -> l = setzero(v -> l, tl, tm, pos);
    else
        v -> r = setzero(v -> r, tm + 1, tr, pos);
    
    upd(v);
    return v;
}

void fight(int x, int k, int it) {
    int pref = getlen(root[x]) - k - 1;

    if (getmn(root[x]) > pref) {
        dead[x] = it;
        return;
    }

    int pos = findpos(root[x], L, R, pref);
    root[x] = setzero(root[x], L, R, pos);
    if (pos != pref)
        root[x] = makeones(root[x], ones, L, R, pos + 1, pref);

    if (getmn(root[x]) == inf) {
        dead[x] = it;
    }
}

void print(node* v, int tl, int tr) {
    if (getlen(v) == 0)
        return;
    if (tl == tr) {
        if (getmn(v) == inf)
            cout << 0 << ' ';
        else
            cout << 1 << ' ';
        return;
    }
    int tm = (tl + tr) >> 1;

    if (!v) {
        print(0, tl, tm);
        print(0, tm + 1, tr);
    } else {
        print(v->l, tl, tm);
        print(v->r, tm + 1, tr);
    }
}

int main() {
    if (R != 250000) {
        cout << "fix R for me please\n";
    }
    int n;
    // freopen("input.txt", "r", stdin);

    cin >> n;

    int k = 0;

    ones = new node();
    init_ones(ones, L, R);
    init_single();

    // return 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            // make (a = 1, h = 1)

            dead[k] = -1;
            root[k] = cpy(single);
            attack[k] = 0; // 2 ^ 0

            k++;

        } else if (t == 2) {
            int x;
            cin >> x;
            x--;

            if (dead[x] != -1) {
                continue;
            }

            attack[x] += 1; // a *= 2
        } else if (t == 3) {
            int x;
            cin >> x;
            x--;
            if (dead[x] != -1) {
                continue;
            }
            
            int curlen = getlen(root[x]);
            root[x] = setzero(root[x], L, R, curlen); // h *= 2
        } else if (t == 4) {
            int x;
            cin >> x;
            x--;

            if (dead[x] != -1) {
                dead[k] = i + 1;
                k++;
                continue;
            }
            
            dead[k] = -1;
            attack[k] = attack[x];
            root[k] = cpy(root[x]);
            k++;

            // cpy 
        } else if (t == 5) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            
            if (dead[x] != -1 || dead[y] != -1) {
                continue;
            }
            
            fight(x, attack[y], i + 1);
            fight(y, attack[x], i + 1);

            // sub
        }

        // cout << k << endl;
        // for (int i = 0; i < k; i++)
        //     cout << attack[i] << ' ';
        // cout << endl << endl;


        // cout << getlen(root[0]) << endl;
        // print(root[0], L, R);
        // cout << endl;
    }

    cout << k << "\n";
    for (int i = 0; i < k; i++)
        cout << dead[i] << ' ';
    return 0;
}