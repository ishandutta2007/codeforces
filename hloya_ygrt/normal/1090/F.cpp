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

int ans[maxn], b[maxn];

map<vector<int>, int> asked;

int ask(vector<int> x) {
    sort(all(x));

    if (asked.count(x)) {
        return asked[x];
    }

    if (x.size() != 3) assert(0);
    cout << "? ";
    for (int i = 0; i < 3; i++) {
        cout << x[i] + 1;
        if (i != 2)
            cout << ' ';
    }
    cout << endl;
    cout.flush();

    int y;
    cin >> y;
    asked[x] = y;

    return y;
}

vector<int> recalc4(vector<int> index) {
    vector<int> al;
    for (int i = 0; i < 4; i++) {
        vector<int> q;
        for (int j = 0; j < 4; j++)
            if (i != j)
                q.pb(index[j]);
        int sum = ask(q);
        al.pb(sum);

        // cout << sum << endl;
    }
    // cout << endl;
    return al;
}

int us[5];
vector<int> g[5];
int val[5][5];

vector<int> st;
bool fnd;
vector<int> res;

void ce() {
    res.clear();
    st.clear();
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            val[i][j] = -1;
    fnd = 0;
    for (int i = 0; i < 5; i++) {
        us[i] = -1;
        g[i].clear();
    }
}

void ae(int i, int j, int sum) {
    // cout << i << ' ' << j << ' ' << sum << endl;
    assert(val[i][j] == sum || val[i][j] == -1);
    g[i].pb(j);
    g[j].pb(i);
    val[i][j] = val[j][i] = sum;
}

void go(int v) {
    for (int to : g[v]) {
        if (res[to] == -1) {
            res[to] = val[v][to] - res[v];
            go(to);
        }
    }
}

void find_cycle(vector<int> vert) {
    fnd = 1;
    ll s = 0;
    int zn = 1;

    vector<pair<ll, int> > re;
    re.pb(mp(0, 1));

    for (int i = 1; i < vert.size(); i++) {
        ll cur = val[vert[i - 1]][vert[i]];
        s = cur - s;
        zn *= -1;

        // cout << s << ' ' << zn << endl;
        re.pb(mp(s, zn));
    }

    // exit(0);
    
    assert(zn == 1);

    ll x = val[vert[0]][vert.back()] - s;
    // cout << s << endl;
    // exit(0);
    assert(x % 2 == 0);

    ll a = x / 2;

    res.assign(5, -1);
    res[vert[0]] = a;

    go(vert[0]);
}

void dfs(int v, int c) {
    us[v] = c;
    st.pb(v);

    for (int to : g[v]) {
        if (us[to] == c) {
            vector<int> vert;

            while (st.back() != to) {
                vert.pb(st.back());
                st.pop_back();
            }

            vert.pb(to);

            find_cycle(vert);
            return;
        } else if (us[to] == -1) {
            dfs(to, c ^ 1);
            if (fnd)
                return;
        }
    }

    st.pop_back();
}

vector<int> vost_nums() {
    dfs(0, 0);
    assert(fnd);
    return res;
}

void recalc5(vector<int> index) {
    vector<pair<vector<int>, int> > vect;
    for (int i = 0; i < index.size(); i++) {
        vector<int> a;

        for (int j = 0; j < index.size(); j++)
            if (i != j)
                a.pb(index[j]);
        
        vector<int> values = recalc4(a);
        
        sort(all(values));
        reverse(all(values));

        // for (int i : values)
        //     cout << i << ' ';
        // cout << endl;

        vect.pb(mp(values, i));  
    }

    vector<int> ord(5);

    sort(all(vect));
    reverse(all(vect));
    
    for (int i = 0; i < 5; i++) {
        ord[i] = vect[i].s;
        // cout << ord[i] << endl;
    }
    // reverse(all(ord));


    // exit(0);


    ce();
    for (int i = 0; i < 5; i++) {
        int cur = vect[i].s;
        vector<int> values = vect[i].f;

        // cout << cur << endl;

        // for (int i : values)
        //     cout << i << ' ';
        // cout << endl;

        vector<int> th;
        for (int j = 0; j < 5; j++)
            if (j != i)
                th.pb(vect[j].s);

        // ae(ord[th[1]], ord[th[3]], values[0]);
        // ae(ord[th[0]], ord[th[3]], values[1]);
        // assert(values[1] == values[2]);
        // ae(ord[th[0]], ord[th[2]], values[3]);


        ae(th[1], th[3], values[0]);
        ae(th[0], th[3], values[1]);
        assert(values[1] == values[2]);
        ae(th[0], th[2], values[3]);
    }

    // exit(0);

    // exit(0);

    vector<int> nums = vost_nums();

    for (int i = 0; i < 5; i++) {
        ans[index[i]] = nums[i];
    }
}

int main() {
    
    srand(time(0));
    // gen();
    // return 0;
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    // for (int i = 0; i < n; i++)
    //     cin >> b[i];

    // recalc5({0, 1, 2, 3, 4});

    for (int i = 0; i < n; i += 5) {
        vector<int> x;
        for (int j = i; j < i + 5; j++)
            x.pb(j % n);
        recalc5(x);
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        // if (i != n - 1)
        //     cout << ' '
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}