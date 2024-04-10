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
const ll N = 1001;
//const int M = 10000000;

vector<int> getZ(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
        string res = "";
        for (int i = 0; i < n; ++i)
            res += '1';
        cout << res << endl;
        return;
    }
    vector<int> z = getZ(s);
    vector<int> val(n, 0);
    for (ll i = 1; i < k; ++i) {
        for (ll j = 1; j * i < n; ++j) {
            ll l = j * i;
            if (z[l] >= j)
                ++val[j];
        }
    }
    for (int i = 1; i < n; ++i) {
        if (val[i] >= k - 1)
            val[i] = 1;
        else
            val[i] = 0;
    }
    vector<pii> seg;
    for (ll i = 1; i < n; ++i) {
        if (val[i]) {
            if (i * k < n)
                seg.push_back(pii(i * k - 1, min(i * (k + 1) - 1, z[i * k] + i * k - 1)));
            else
                seg.push_back(pii(i * k - 1, i * k - 1));
        }
    }
    sort(seg.begin(), seg.end());
    vector<int> res(n, 0);
    int r = -1;
    for (int i = 0; i < seg.size(); ++i) {
        r = max(r, seg[i].first);
        while (r <= seg[i].second) {
            res[r] = 1;
            ++r;
        }
    }
    string ans = "";
    for (int i = 0; i < res.size(); ++i)
        if (res[i])
            ans += '1';
        else
            ans += '0';
    cout << ans << endl;
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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