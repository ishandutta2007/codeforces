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
const ll mod = 1000000007;

const int N = 10000 + 5;


void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector<int> s1, s2;
    for (int i = 0; i < n; ++i) {
        if (b[i])
            s2.push_back(a[i]);
        else
            s1.push_back(a[i]);
    }
    if (s2.empty()) {
        cout << 0 << endl;
        return;
    }
    sort(s2.rbegin(), s2.rend());
    vector<ll> sum2(s2.size() + 1);
    sum2[0] = 0;
    for (int i = 0; i < s2.size(); ++i) {
        sum2[i + 1] = sum2[i] + s2[s2.size() - 1 - i];
    }
    vector<int> d(N, n + 5);
    d[0] = 0;
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = N - 1; j >= s1[i]; --j) {
            d[j] = min(d[j], d[j - s1[i]]);
        }
    }
    ll res = 0;
    for (int i = 0; i <= s2.size(); ++i) {
        ll id = s2.size();
        for (int j = l; j <= r; ++j) {
            if (d[j] > n)
                continue;
            ll sp = r - j;
            while (sum2[id] > sp)
                --id;
            ll cur = min(id, (ll)s2.size() - i);
            if ((cur + d[j] < (ll)s2.size()))
                ++cur;
            res = max(res, cur);
        }
        if (i == s2.size())
            break;
        for (int j = N - 1; j >= s2[i]; --j) {
            d[j] = min(d[j], d[j - s2[i]] + 1);
        }
    }
    cout << res << endl;

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