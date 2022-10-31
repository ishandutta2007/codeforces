//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;

#define next ajksdslk

struct node {
    int sum[2];
    node* l, * r;
    int tp;
    node() {
        tp = -1;
        l = 0, r = 0;
        sum[0] = sum[1] = 0;
    }
};
node* root = new node();

void add(node* v, int pos, int cur, const vector<int>& path) {
    if (pos == path.size()) {
        if (v->sum[1 ^ cur]) {
            cout << -1 << "\n";
            exit(0);
        }
        v->tp = cur;
        v->sum[cur] += 1;
        return;
    }
    if (v->tp != -1 && v->tp != cur) {
        cout << -1 << "\n";
        exit(0);
    }
    if (path[pos] == 0) {
        if (!(v->l))
            v->l = new node();
        add(v->l, pos + 1, cur, path);
        v->sum[cur] += 1;
    } else {
        if (!(v->r))
            v->r = new node();
        add(v->r, pos + 1, cur, path);
        v->sum[cur] += 1;
    }
}

int ans = 0;

//string to_string(int x) {
//    if (x == 0) return "0";
//    string s;
//    while (x) {
//        s += '0' + x % 10;
//        x /= 10;
//    }
//    reverse(all(s));
//    return s;
//}

vector<string> res;

void rec(node* v, ll l = 0, int d = 0) {
    if (!v) {
        return;
    }
    if (v->sum[1] == 0)
        return;
    if (v->sum[0] == 0) {
        ans++;

        for (int i = 0; i < 32 - d; i++)
            l *= 2;
        vector<int> bt;
        for (int i = 0; i < 32; i++) {
            bt.pb(l % 2);
            l /= 2;
        }
        reverse(all(bt));

        string s;
        for (int j = 0; j < 32; j += 8) {
            int x = 0;
            for (int k = j; k < j + 8; k++)
                x *= 2, x += bt[k];
            s += to_string(x);
            s += '.';
        }
        s.pop_back();

        s.pb('/');
        s += to_string(d);
        res.pb(s);
        return;
    }

    rec(v->l, l * 2, d + 1);
    rec(v->r, l * 2 + 1, d + 1);
}

int main() {
//    freopen ("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    string s = "a";
//    cout << (s.find("/") == -1);
//    return 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cur = s[0] == '-';
        s.erase(s.begin());

        int p = s.find('/');

        if (p == -1) {
            int lst = 0;
            vector<int> pth;
            s += '.';
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '.') {
                    vector<int> cur;
                    for (int j = 0; j < 8; j++) {
                        cur.pb(lst % 2);
                        lst /= 2;
                    }
                    reverse(all(cur));
                    for (int j : cur)
                        pth.pb(j);
                    lst = 0;
                } else {
                    lst = lst * 10 + s[i] - '0';
                }
            }
//            exit(0);
            assert(pth.size() <= 32);
            add(root, 0, cur, pth);
        } else {
            int x = 0;
            for (int i = p + 1; i < s.size(); i++) {
                x = x * 10 + s[i] - '0';
            }
            s.resize(p);

            int lst = 0;
            vector<int> pth;
            s += '.';
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '.') {
                    vector<int> cur;
                    for (int j = 0; j < 8; j++) {
                        cur.pb(lst % 2);
                        lst /= 2;
                    }
                    reverse(all(cur));
                    for (int j : cur)
                        pth.pb(j);
                    lst = 0;
                } else {
                    lst = lst * 10 + s[i] - '0';
                }
            }
            assert(pth.size() <= 32);
            while (pth.size() > x)
                pth.pop_back();
            add(root, 0, cur, pth);
        }
    }

    rec(root);
    cout << ans << "\n";

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
    return 0;

}