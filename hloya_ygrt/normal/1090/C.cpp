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

const int maxn = (int) 1e5 + 5;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

#define ull unsigned long long

struct node {
    int cnt;
    node* l, * r;

    node() {
        cnt = 0;
        l = 0;
        r = 0;
    }
};

int getcnt(node* v) {
    if (!v) return 0;
    return v -> cnt;
}

void upd(node* v) {
    v -> cnt = getcnt(v->l) + getcnt(v->r);
}

void add(node* v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        v -> cnt += x;
        assert(v -> cnt == 0 || v -> cnt == 1);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        if ((v -> l) == 0) {
            v -> l = new node();
        }
        add(v -> l, tl, tm, pos, x);
    } else {
        if ((v -> r) == 0) {
            v -> r = new node();
        }
        add(v -> r, tm + 1, tr, pos, x);
    }
    upd(v);
}

node* getleft(node* v) {
    if (!v) return 0;
    return v->l;
}

node* getright(node* v) {
    if (!v) return 0;
    return v->r;
}

int diff(node* v1, node* v2, int tl, int tr) {
    assert(getcnt(v1) != getcnt(v2));

    if (tl == tr) {
        assert(getcnt(v2) != 0);
        return tl;
    }

    int tm = (tl + tr) >> 1;

    if (getcnt(getleft(v1)) < getcnt(getleft(v2))) {
        return diff(getleft(v1), getleft(v2), tl, tm);
    } else {
        return diff(getright(v1), getright(v2), tm + 1, tr);
    }
}

node* root[maxn];

void gen() {
    ofstream cout("input.txt");
    int n = rand() % 10 + 1, m = rand() % 10 + 1;
    cout << n << ' ' << m << endl;

    for (int i = 0; i < n; i++) {
        int x = rand() % (m + 1);
        set<int> s;

        for (int j = 0; j < x; j++)
            s.insert(rand() % m + 1);
        cout << s.size() << ' ';
        for (int x : s)
            cout << x << ' ';
        cout << endl;
    }
}

int main() {
    
    srand(time(0));
    // gen();
    // return 0;
    // freopen("input.txt", "r", stdin);

    int n, m;

    cin >> n >> m;


    for (int i = 0; i < n; i++)
        root[i] = new node();

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    set<pair<int, int> > q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        q.insert(mp(x, i));

        while (x--) {
            int y;
            cin >> y;
            y--;
            add(root[i], 0, m - 1, y, +1);
        }
    }

    vector<tuple<int, int, int> > ans;
    while (1) {
        auto i = q.begin()->s;
        auto j = (--q.end())->s;

        int s1 = q.begin()->f;
        int s2 = (--q.end())->f;

        q.erase(q.begin());
        q.erase(--q.end());

        if (s2 - s1 <= 1) {
            break;
        }

        int pos = diff(root[i], root[j], 0, m - 1);
        // cout << j + 1 << ' ' << i + 1<< ' ' << pos + 1 << endl;

        ans.pb(mt(j + 1, i + 1, pos + 1));

        add(root[i], 0, m - 1, pos, +1);
        add(root[j], 0, m - 1, pos, -1);
        
        q.insert(mp(s1 + 1, i));
        q.insert(mp(s2 - 1, j));
    }

    // exit(0);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        int a, b, c;
        tie(a, b, c) = ans[i];
        cout << a << ' ' << b << ' ' << c << "\n";
    }
    return 0;
}