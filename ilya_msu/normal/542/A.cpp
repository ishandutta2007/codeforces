#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

struct channel {
    int l, r, id;
    ll c;   
};


ll res = 0;
int id1, id2;

bool compl(const channel& a, const channel& b) {
    return a.l < b.l;
}

bool compr(const channel& a, const channel& b) {
    return a.r < b.r;
}

void solve1(vector<channel> a, vector<channel> b) {
    int n = a.size(), m = b.size();
    sort(a.begin(), a.end(), compl);
    vector<int> maxR(n), maxRInd(n);
    maxR[0] = a[0].r;
    maxRInd[0] = 0;
    for (int i = 1; i < n; ++i) {
        maxR[i] = maxR[i - 1];
        maxRInd[i] = maxRInd[i - 1];
        if (a[i].r > maxR[i]) {
            maxR[i] = a[i].r;
            maxRInd[i] = i;
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        int left = b[i].l;
        int down = -1, up = n;
        while (up - down > 1) {
            int mid = (down + up) / 2;
            if (a[mid].l <= left)
                down = mid;
            else
                up = mid;
        }
        if (down >= 0) {
            ll curRes = b[i].c * (min(maxR[down], b[i].r) - left);
            if (curRes > res) {
                res = curRes;
                id1 = a[maxRInd[down]].id;
                id2 = b[i].id;
            }
        }
    }
}

void solve2(vector<channel> a, vector<channel> b) {
    for (int i = 0; i < a.size(); ++i) {
        swap(a[i].l, a[i].r);
        a[i].l *= -1;
        a[i].r *= -1;
    }
    for (int i = 0; i < b.size(); ++i) {
        swap(b[i].l, b[i].r);
        b[i].l *= -1;
        b[i].r *= -1;
    }
    solve1(a, b);
}

struct SegTree {
    int n;
    vector<pii> t;
    //vector<int> ind;
    SegTree(int nn) {
        n = nn;
        t.assign(4 * n + 10, pii(0, -1));
        //ind.assign(t.size(), -1);
    }
    pii getMax(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return pii(0, -1);
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return max(getMax(v * 2, tl, tm, l, min(r, tm)), getMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = pii(new_val, pos);
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
};

void solve3(vector<channel> a, vector<channel> b) {
    for (int i = 0; i < b.size(); ++i)
        a.push_back(b[i]);
    vector<pii> lefts(a.size());
    for (int i = 0; i < a.size(); ++i) {
        lefts[i] = pii(a[i].l, a[i].id);
    }
    sort(lefts.begin(), lefts.end());
    map<pii, int> index;
    vector<int> idd1(lefts.size());;
    for (int i = 0; i < lefts.size(); ++i) {
        index[lefts[i]] = i;
        idd1[i] = lefts[i].second;

    }
    sort(a.begin(), a.end(), compr);
    SegTree tr(a.size() + 1);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].c == -1) {
            tr.update(1, 0, a.size(), index[pii(a[i].l, a[i].id)], a[i].r - a[i].l);
            continue;
        }
        pii x = tr.getMax(1, 0, a.size(), index[pii(a[i].l, a[i].id)], a.size());
        ll curRes = a[i].c * x.first;
        if (curRes > res) {
            res = curRes;
            id1 = idd1[x.second];
            id2 = a[i].id;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<channel> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        a[i].c = -1;
    }
    vector<channel> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].l >> b[i].r >> b[i].c;
        b[i].id = i;
    }
    solve1(a, b);
    //cerr << res << endl;
    solve2(a, b);
    //cerr << res << endl;
    solve3(a, b);
    cout << res << endl;
    if (res) {
        assert(res == b[id2].c * (min(b[id2].r, a[id1].r) - max(a[id1].l, b[id2].l)));

        cout << id1 + 1 << " " << id2 + 1 << endl;
    }

    
}



//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}