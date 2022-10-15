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
#include<bitset>




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
ll mod = 1000 * 1000 * 1000 + 7;

const int V = 7001;
const int N = 100000 + 20;


void solve() {
    vector<bitset<V> > a(N), b(V), c(V);
    int n, q;
    cin >> n >> q;
    vector<int> bad(N, 0);
    for (ll i = 2; i < N; ++i) {
        for (ll j = i * i; j < N; j += i * i)
            bad[j] = 1;
    }
    for (int i = 1; i < V; ++i) {
        for (int j = 1; j < V; ++j) {
            b[i][j] = (i % j == 0);
        }
        for (int j = 1; j * i < V; ++j) {
            if (!bad[j])
                c[i][i * j] = 1;
        }
    }
    for (int qq = 0; qq < q; ++qq) {
        int t, x, y, z, v;
        cin >> t;
        if (t == 1) {
            cin >> x >> v;
            a[x] = b[v];
        }
        else if (t == 2) {
            cin >> x >> y >> z;
            a[x] = a[y] ^ a[z];
        }
        else if (t == 3) {
            cin >> x >> y >> z;
            a[x] = a[y] & a[z];
        }
        else {
            cin >> x >> v;
            cout << (a[x] & c[v]).count() % 2;
        }
    }
    cout << endl;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);//cout.tie(nullptr);
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