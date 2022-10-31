//           
//         
//     
//     
//        
//           
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <complex>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;



int A, B;
int n, k;

struct tree {
    tree *l = 0, *r = 0;

    int sum = 0;
    ll ans = 0;
    int len = 0;

    tree (int sum, int len) : sum(sum), len(len), l(0), r(0) {
        if (sum == 0) ans = 1ll * A;
        else ans = 1ll * sum * B * len;
    };


    tree (tree * l, tree * r) : l(l), r(r) {
        sum = l->sum + r->sum ;
        len = l->len + r->len;
        if (sum == 0) ans = 1ll * A;
        else ans = min(l->ans + r->ans, 1ll * sum * len * B);
    }
};

tree * root = nullptr;

void upd(tree *&v, int l, int r, int pos, int sum) {
//    cout << v->len << " " << l << " " << r << " " << pos << " " << sum << endl;

    if (l == r) {
        v = new tree(sum, 1);
    } else {
        int m = (l + r) >> 1;
        if (!v->l) v->l = new tree(0, m - l + 1);
        if (!v->r) v->r = new tree(0, r - m);
        if (pos <= m) {
            upd(v->l, l, m, pos, sum);
        } else {

            upd(v->r, m + 1, r, pos, sum);
        }
        v = new tree(v->l, v->r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k >> A >> B;
    root = new tree(0, (1 << n));

    map<int,int> cnt;

    for (int i = 1; i <= k; i ++) {
        int x; cin >> x;
        cnt[x] ++;
    }

    int N = (1 << n);
    for (auto & e : cnt) {
        upd(root, 1, N, e.fst, e.snd);
//        cout << e.fst << " " << e.snd << '\n';
    }

    cout << root->ans << '\n';
    return 0;

}