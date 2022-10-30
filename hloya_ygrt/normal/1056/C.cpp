#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <algorithm>
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

const int maxn = (int) 1e5 + 25;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

int p[maxn];
bool us[maxn];

bool cmp(pii a, pii b) {
    return p[a.f] > p[b.f];
}

bool cmp2(int a, int b) {
    return p[a] > p[b];
}

int drug[maxn];
bool ch[maxn];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 2 * n; i++) {
        cin >> p[i];
        drug[i] = -1;
    }

    vector<pii> pr;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        if (p[a] < p[b])
            swap(a, b);

        drug[a] = b;
        drug[b] = a;

        us[a] = us[b] = 1;

        pr.pb(mp(a, b));
    }

    sort(all(pr), cmp);


    vector<int> oth;
    for (int i = 0; i < 2 * n; i++)
        if (!us[i])
            oth.pb(i);
    sort(all(oth), cmp2);

    int t;
    cin >> t;

    int ban = 0;

    if (t == 2) {
        while (ban < 2 * n) {
            int x;
            cin >> x;
            x--;
            ch[x] = 1;
            ban++;
            if (drug[x] != -1) {
                int my_turn = drug[x];
                cout << my_turn + 1 << endl;
                cout.flush();
                ch[my_turn] = 1;
                ban++;
            } else break;
        }
    }

    for (int i = 0; i < pr.size(); i++) {
        if (!ch[pr[i].f]) {
            int my_turn = pr[i].f;
            cout << my_turn + 1 << endl;
            cout.flush();
            ch[my_turn] = 1;
            ban++;

            int x;
            cin >> x;
            x--;
            ch[x] = 1;
            ban++;
            assert(x == pr[i].s);
        }
    }

    for (int i = 0; i < oth.size(); i++) {
        if (!ch[oth[i]]) {
            int my_turn = oth[i];

            cout << my_turn + 1 << endl;
            cout.flush();
            ch[my_turn] = 1;
            ban++;

            if (ban != 2 * n) {
                int x;
                cin >> x;
                x--;
                ch[x] = 1;
                ban++;
            }

        }
    }
    return 0; 
}