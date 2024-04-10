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
#include<deque>




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
    int n, q;
    cin >> n >> q;
    deque<int> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d.push_back(a[i]);
    }
    vector<pii> res(q);
    vector<ll> qq(q);
    for (int i = 0; i < q; ++i) {
        cin >> qq[i];
    }
    vector<pii> ans(2 * n + 5);
    for (int i = 1; i < ans.size(); ++i) {
        //cerr << i << endl;
        int a = d.front();
        d.pop_front();
        int b = d.front();
        d.pop_front();
        ans[i] = pii(a, b);
        if (a > b) {
            d.push_front(a);
            d.push_back(b);
        }
        else {
            d.push_front(b);
            d.push_back(a);
        }
    }
    for (int i = 0; i < q; ++i) {
        if (qq[i] < ans.size()) {
            cout << ans[qq[i]].first << " " << ans[qq[i]].second << "\n";
        }
        else {
            ll x = qq[i] % (n - 1);
            x += n - 1;
            cout << ans[x].first << " " << ans[x].second << "\n";
        }
    }

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