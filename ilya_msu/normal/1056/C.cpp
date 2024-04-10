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
//const ll mod = 1000 * 1000 * 1000 + 7;
const ll mod = 1000 * 1000 * 1000 + 7;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> used(2 * n + 1, 0);
    vector<int> p(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i)
        cin >> p[i + 1];
    vector<int> e(2 * n + 1, 0);
    int a, b;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        e[a] = b;
        e[b] = a;
    }
    int t;
    cin >> t;
    int lst = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if ((t ^ i) & 1) {
            if ((lst != 0) && (e[lst] != 0) && (used[e[lst]] == 0)) {
                cout << e[lst] << endl;
                used[e[lst]] = 1;
                continue;
            }
            int id = 0;
            for (int j = 1; j <= 2 * n; ++j) {
                if (used[j]) 
                    continue;
                if (e[j] != 0) {
                    id = j;
                    if (p[e[id]] > p[id])
                        id = e[id];
                    break;
                }
                if (p[j] > p[id]) {
                    id = j;
                }
            }
            cout << id << endl;
            used[id] = 1;
        }
        else {
            cin >> lst;
            used[lst] = 1;
        }
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