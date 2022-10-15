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
    vector<ll> v(n), t(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    vector<ll> a(n + 2, 0);
    vector<ll> sum(n + 1, 0);
    sum[0] = t[0];
    for (int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + t[i];
    sum[n] = INF + sum[n - 1];
    vector<ll> res(n, 0);
    for (int i = 0; i < n; ++i) {
        ll vol = v[i];
        if (i)
            vol += sum[i - 1];
        int pos = lower_bound(sum.begin(), sum.end(), vol) - sum.begin();
        ++a[i];
        --a[pos + 1];
        if (pos < n)
            res[pos] -= sum[pos] - vol;
    }
    for (int i = 1; i < a.size(); ++i)
        a[i] += a[i - 1];
    for (int i = 0; i < n; ++i)
        res[i] += a[i] * t[i];
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;

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