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
const int N = 1000000;


int getRes(const string& s) {
    int n = s.size();
    int res = -1;
    int sum = 0;
    int st = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            ++sum;
        else
            --sum;
        if (sum < 0) {
            sum = 0;
            if (res < i - 1 - st) {
                res = i - 1 - st;
            }
            st = i;
        }
    }
    if (sum == 0)
        res = max(res, n - 1 - st);
    return res;
}


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int res = getRes(s);
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i)
        if (s[i] == '(')
            s[i] = ')';
        else
            s[i] = '(';
    res = max(res, getRes(s));
    int sum = 0;
    int st = -1;
    set<int> count;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            ++sum;
        else
            --sum;
        if ((sum == 0) && (i - st == res)) {
            count.insert(st + 1);
            st = i;
        }
        if (sum < 0) {
            sum = 0;
            st = i;
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i)
        if (s[i] == '(')
            s[i] = ')';
        else
            s[i] = '(';
    sum = 0;
    st = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            ++sum;
        else
            --sum;
        if ((sum == 0) && (i - st == res)) {
            count.insert(n - 1 - st - 1 - res + 1);
            st = i;
        }
        if (sum < 0) {
            sum = 0;
            st = i;
        }
    }
    int ans = count.size();
    if (res == 0)
        ans = 1;
    cout << res << " " << ans << endl;

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