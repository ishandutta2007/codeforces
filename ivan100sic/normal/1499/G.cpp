// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

#ifdef LOCAL
const int N = 45;
#else
const int N = 400005;
#endif

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const {	return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

mint pw[N];
int a, b, m;

struct path {
    list<int> v;
    mint h, hc;

    void reverse() {
        if (v.size() % 2) {
            swap(h, hc);
        }
        v.reverse();
    }

    void merge(path&& b, int eid) {
        if (v.size() % 2) {
            h += pw[eid];
            swap(b.h, b.hc);
        } else {
            hc += pw[eid];
        }

        v.splice(v.end(), b.v);
        h += b.h;
        hc += b.hc;
    }
};

path p[N];
int le[N];
mint hsum;
map<pair<int, int>, int> vid;
vector<int> permared;

void set_vid(int x, int y, int eid) {
    if (x > y) swap(x, y);
    vid[{x, y}] = eid;
}

int get_vid(int x, int y) {
    if (x > y) swap(x, y);
    auto it = vid.find({x, y});
#ifdef LOCAL
    if (it == vid.end()) {
        cerr << "hmm\n";
        return -1;
    } else {
        return it->second;
    }
#else
    return it->second;
#endif
}

void reverse(int x) {
    if (!le[x]) return;
    x = le[x];
    
    hsum -= p[x].h;
    p[x].reverse();
    hsum += p[x].h;

    int f = p[x].v.front();
    int l = p[x].v.back();

    le[f] = le[l] = f;
    swap(p[f], p[l]);
    p[l].v = { l };
}

int startof(int x) {
    if (le[x] == 0) return x;
    return le[x];
}

void simple_merge(int x, int y, int eid) {
    x = startof(x);
    y = startof(y);

    if (le[x]) {
        le[p[x].v.back()] = 0;
    }

    if (le[y]) {
        le[p[y].v.front()] = 0;
    }

    le[x] = x;
    le[p[y].v.back()] = x;

    set_vid(p[x].v.back(), p[y].v.front(), eid);

    hsum -= p[x].h + p[y].h;
    p[x].merge(move(p[y]), eid);
    // update p[y] data
    p[y].v = {y};
    p[y].h = p[y].hc = 0;
    hsum += p[x].h;
}

void debug_paths() {
#ifdef LOCAL
    for (int x=1; x<=a+b; x++) cerr << le[x] << " \n"[x == a+b];
    for (int x=1; x<=a+b; x++) {
        if (le[x] == x) {
            cerr << "path:";
            for (int y : p[x].v) {
                cerr << ' ' << y;
            }
            cerr << '\n';
        }
    }
    cerr << '\n';
#endif
}

bool isleft(int x) {
    return le[x] == 0 || le[x] == x;
}

bool isright(int x) {
    return le[x] != x;
}

void add_edge(int x, int y, int eid) {
    if (le[x] && le[x] == le[y]) {
        // tear it apart, add edges to permanent red
        int node = le[x];
        auto& v = p[node].v;
        for (auto it = v.begin(); it != v.end() && next(it) != v.end(); it = next(next(it))) {
            int x = *it;
            int y = *next(it);
            int id = get_vid(x, y);
            permared.push_back(id);
            hsum += pw[id];
        }

        hsum -= p[node].h;

        p[node].h = p[node].hc = 0;
        p[x].v = {x};
        p[y].v = {y};
        le[x] = le[y] = 0;

        return;
    }

    int steps = 0;
    while (1) {
        steps++;
        if (steps == 3) {
            exit(p[startof(x)].v.size() * 10000 + p[startof(y)].v.size());
        }

        if (isleft(y) && isright(x)) {
            simple_merge(x, y, eid);
            break;
        } else if (isleft(x) && isright(y)) {
            simple_merge(y, x, eid);
            break;
        } else {
            int xs = p[startof(x)].v.size();
            int ys = p[startof(y)].v.size();
            if (xs < ys) {
                reverse(x);
            } else {
                reverse(y);
            }
        }
    }
}

void print_hash() {
    cout << hsum() << '\n' << flush;
}

void print_coloring() {
    vector<int> c = permared;
    for (int x=1; x<=a+b; x++) {
        if (le[x] == x) {
            auto& v = p[x].v;
            for (auto it = v.begin(); it != v.end() && next(it) != v.end(); it = next(next(it))) {
                int x = *it;
                int y = *next(it);
                int id = get_vid(x, y);
                c.push_back(id);
            }
        }
    }

#ifdef LOCAL
    mint hsum_check = 0;
    for (int x : c) hsum_check += pw[x];
    if (hsum_check != hsum) {
        cerr << "Sum mismatch\n";
    }
#endif

    cout << c.size();
    for (int x : c) cout << ' ' << x;
    cout << '\n' << flush;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> a >> b >> m;

    pw[0] = 1;
    for (int i=1; i<N; i++) {
        pw[i] = pw[i-1] + pw[i-1];
    }

    for (int i=1; i<=a+b; i++) {
        p[i].v = {i};
    }

    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        add_edge(x, a+y, i);
    }

    debug_paths();

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            add_edge(x, a+y, ++m);
            print_hash();
        } else {
            print_coloring();
        }

        debug_paths();
    }
}