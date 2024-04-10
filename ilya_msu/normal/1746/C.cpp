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
#include<unordered_set>
#include<chrono>
#include<random>
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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> d(n);
    vector<pii> p;
    for (int i = 1; i < n; ++i) {
        d[i] = max(0, a[i - 1] - a[i]);
        p.push_back(pii(d[i], i));
    }
    sort(p.begin(), p.end());
    vector<int> res(n + 1, 1);
    for (int i = 0; i < n - 1; ++i) {
        res[i + 1] = p[i].second + 1;
    }
    for (int i = 0; i < n; ++i)
        cout << res[i + 1] << " ";
    cout << "\n";

    
        
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}