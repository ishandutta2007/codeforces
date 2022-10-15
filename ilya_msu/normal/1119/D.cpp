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
const ll mod = 1000 * 1000 * 1000 + 7;



void solve() {
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    sort(s.begin(), s.end());
    vector<ll> d;
    for (int i = 0; i < n - 1; ++i)
        d.push_back(s[i + 1] - s[i]);
    sort(d.begin(), d.end());
    vector<ll> sm(n, 0);
    for (int i = 1; i < n; ++i)
        sm[i] = sm[i - 1] + d[i - 1];
    int q;
    cin >> q;
    ll l, r;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        ll len = r - l + 1;
        int id = lower_bound(d.begin(), d.end(), len) - d.begin();
        ll res = len * (n - id) + sm[id];
        cout << res << " ";
    }
    cout << endl;


}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

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