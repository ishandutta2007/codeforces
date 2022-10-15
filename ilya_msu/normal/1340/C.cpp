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
#include<unordered_map>




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
    vector<int> dd(m);
    for (int i = 0; i < m; ++i) {
        cin >> dd[i];
    }
    sort(dd.begin(), dd.end());
    int t1, t2;
    cin >> t1 >> t2;
    vector<vector<int> > gg(2, vector<int> (m * t1, -1));
    for (int i = 0; i + 1 < m; ++i) {
        for (int j = 0; j <= t1; ++j) {
            int v1 = i * (t1) + j;
            int ii = i + 1;
            int j1 = j + dd[i + 1] - dd[i];
            int j2 = j - dd[i + 1] + dd[i];
            int u1 = ii * (t1) + j1;
            int u2 = ii * (t1) + j2;
            if (j1 <= t1) {
                if (j1 == t1)
                    u1 -= t1;
                gg[0][v1] = u1;
            }
            if (j2 >= 0) {
                if (j == t1)
                    v1 -= t1;
                gg[1][u2] = v1;
            }
        }
    }
    

    int N = gg[0].size();
    vector<ll> d(N, -1);
    d[0] = 0;
    queue<int> q1, q2;
    vector<int> D(m, -1);
    D[0] = 0;
    q1.push(0);
    ll k = 0;
    ll res = -1;
    while ((res == -1) && (!q1.empty())) {
        ++k;
        while (!q1.empty()) {
            int v = q1.front();
            q1.pop();
            for (int id = 0; id < 2; ++id) {
                int to = gg[id][v];
                if (to == -1)
                    continue;
                int i1 = to / t1, i2 = to % t1;
                if (d[to] != -1)
                    continue;
                int add = i2;
                if (i2 == 0)
                    add = t1;
                d[to] = (k - 1) * t1 + add;
                if (i1 == m - 1) {
                    if (res == -1)
                        res = d[to];
                    else {
                        res = min(res, d[to]);
                    }
                }
                if (i2 != 0) {
                    q1.push(to);
                }
                else {
                    if (D[i1] == -1) {
                        q2.push(to);
                        D[i1] = k;
                    }
                }
            }
        }
        swap(q1, q2);
    }
    
    if (res == -1) {
        cout << res << endl;
        return;
    }   
    ll qq = (res + t1 - 1) / (t1);

    res += (qq - 1) * t2;
    cout << res << endl;


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