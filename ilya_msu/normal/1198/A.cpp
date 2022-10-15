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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;




void solve() {
    int n, I;
    cin >> n >> I;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int K = 8 * I / n;
    if (K >= 30) {
        cout << 0 << endl;
        return;
    }
    int k = 1 << K;
    int c = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            ++c;
    }
    if (c <= k) {
        cout << 0 << endl;
        return;
    }
    vector<int> l;
    int x = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1])
            ++x;
        else {
            l.push_back(x);
            x = 1;
        }
    }
    l.push_back(x);
    int sz = l.size();
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += l[i];
    int res = sum;
    for (int i = 1; i + k <= sz; ++i) {
        sum -= l[i - 1];
        sum += l[i + k - 1];
        res = max(res, sum);
    }
    cout << n - res << endl;

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