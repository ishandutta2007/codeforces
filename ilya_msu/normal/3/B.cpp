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
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n, v;
    cin >> n >> v;
    vector<pll> a, b;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int t, p;
        cin >> t >> p;
        if (t == 1)
            a.push_back(pll(p, i + 1));
        else
            b.push_back(pll(p, i + 1));
    }
    sort(a.begin(), a.end());
    ll res = 0;
    if ((v & 1) && (a.size() > 0)) {
        res = a[a.size() - 1].first;
        ans.push_back(a[a.size() - 1].second);
        a.pop_back();
        --v;
    }
    reverse(a.begin(), a.end());
    for (int i = 0; 2 * i + 2 <= a.size(); ++i) {
        b.push_back(pll(a[2 * i].first + a[2 * i + 1].first, a[2 * i].second * 1000000 + a[2 * i + 1].second));
    }
    if (a.size() & 1)
        b.push_back(a[a.size() - 1]);
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int i = 0; (i < v / 2) && (i < b.size()); ++i) {
        res += b[i].first;
        if (b[i].second > 1000000) {
            ans.push_back(b[i].second / 1000000);
        }
        ans.push_back(b[i].second % 1000000);

    }
    cout << res << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
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