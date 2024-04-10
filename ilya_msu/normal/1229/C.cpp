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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > in(n), out(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        in[min(a, b)].push_back(max(a, b));
        out[max(a, b)].push_back(min(a, b));
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res = res + 1LL * in[i].size() * out[i].size();
    }
    cout << res << endl;
    int q, v;
    cin >> q;
    vector<int> sal(n);
    vector<ll> ins(n), outs(n), dg(n);
    for (int i = 0; i < n; ++i) {
        ins[i] = in[i].size();
        outs[i] = out[i].size();
        dg[i] = ins[i] + outs[i];
    }
    for (int i = 0; i < n; ++i)
        sal[i] = i;
    for (int i = 0; i < q; ++i) {
        cin >> v;
        --v;
        for (int j = 0; j < in[v].size(); ++j) {
            //out[v].push_back(in[v][j]);
            in[in[v][j]].push_back(v);
            res -= ins[in[v][j]] * outs[in[v][j]];
            ++ins[in[v][j]];
            --outs[in[v][j]];
            res += ins[in[v][j]] * outs[in[v][j]];
        }
        in[v].resize(0);
        res -= ins[v] * outs[v];
        ins[v] = 0;
        outs[v] = dg[v];
        cout << res << "\n";
    }

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   
        solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}