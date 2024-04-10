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
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n;
    cin >> n;
    map<pll, pll> mp;
    vector<ll> a(3);
    vector<ll> res(n + 1);
    vector<pll> ans(n + 1);
    int x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        pll p(a[1], a[2]);
        res[i + 1] = res[i];
        ans[i + 1] = ans[i];
        
        auto it = mp.find(p);
        if (it != mp.end()) {
            if (min(a[0] + it->second.first, a[1]) > res[i + 1]) {
                res[i + 1] = min(a[0] + it->second.first, a[1]);
                ans[i + 1] = pii(it->second.second, i + 1);
            }
            if (a[0] > it->second.first)
                mp[p] = pii(a[0], i + 1);
        }
        else {
            mp[p] = pii(a[0], i + 1);
        }
        
        if (res[i + 1] < a[0]) {
            res[i + 1] = a[0];
            ans[i + 1] = pii(i + 1, -1);
        }
        if (res[i + 1] > res[i])
            ++x;
        //cerr << res[i + 1] << " " << ans[i + 1].first << " " << ans[i + 1].second << endl;
    }
    //cout << x << endl;
    
    if (ans[n].second == -1) {
        cout << 1 << endl << ans[n].first << endl;
    }
    else {
        cout << 2 << endl << ans[n].first << " " << ans[n].second << endl;
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