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
#include<cmath>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;//1000 * 1000 * 1000 + 7;


vector<int> get1(string s) {
    int n = s.size();
    vector<int> d1(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        if (i <= r)
            k = min(d1[l + r - i], r - i + 1);
        while ((i + k < n) && (i - k >= 0) && (s[i + k] == s[i - k]))  
            ++k;
        d1[i] = k;
        if (i + k - 1 > r)
            l = i - k + 1, r = i + k - 1;
    }
    return d1;
}

vector<int> get2(string s) {
    int n = s.size();
    vector<int> d2 (n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i <= r)
            k = min (d2[l + r - i + 1], r - i + 1);
        while ((i + k < n) && (i - k - 1 >= 0) && (s[i + k] == s[i - k - 1]))
            ++k;
        d2[i] = k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
    return d2;
}

void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        int n = s.size();
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == s[n - 1 - i])
                ++m;
            else 
                break;
        }
        vector<int> d1 = get1(s), d2 = get2(s);
        /*for (int i = 0; i < n; ++i) {
            cout << d1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << d2[i] << " ";
        }
        cout << endl;*/
        int res1 = 0, res2 = 0;
        pii ans1, ans2;
        for (int i = 0; i < n; ++i) {
            int l = i + 1 - d1[i];
            int r = n - i - d1[i];
            int mm = min(l, r);
            int len = 2 * d1[i] - 1 + 2 * mm;
            if ((mm <= m) && (len > res1)) {
                res1 = len;
                if (l <= r) {
                    ans1 = pii(l + 2 * d1[i] - 1, l);
                }
                else {
                    ans1 = pii(r, 2 * d1[i] - 1 + r);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int l = i - d2[i];
            int r = n - i - d2[i];
            int mm = min(l, r);
            int len = 2 * d2[i] + 2 * mm;
            if ((mm <= m) && (len > res2)) {
                res2 = len;
                if (l <= r) {
                    ans2 = pii(l + 2 * d2[i], l);
                }
                else {
                    ans2 = pii(r, 2 * d2[i] + r);
                }
            }
        }
        //cout << res1 << " " << res2 << endl;
        pii ans;
        if (res1 > res2) {
            ans = ans1;
        }
        else ans = ans2;
        cout << s.substr(0, ans.first) << s.substr(n - ans.second, ans.second) << "\n";
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