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

void solve() {
    int n;
    cin >> n;
    cout << "? 1 " << n << endl;
    if (n == 1) {
        string s;
        cin >> s;
        cout << "! " << s << endl;
        return;
    }
    int m = n * (n + 1) / 2;
    map<string, int> mp;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ++mp[s];
    }
    cout << "? 2 " << n << endl;
    m = n * (n - 1) / 2;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        --mp[s];
    }
    vector<string> a;
    for (auto it : mp) {
        if (it.second > 0)
        a.push_back(it.first);
    }
    string res;
    res.resize(n);
    vector<vector<int> > cnt(n + 1, vector<int>(256, 0));
    for (int i = 0; i < a.size(); ++i) {
        string s = a[i];
        cerr << s << endl;
        int k = s.size();
        for (int j = 0; j < k; ++j) {
            ++cnt[k][s[j]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 256; ++j) {
            if (cnt[i][j] > cnt[i - 1][j])
                res[i - 1] = (char)(j);
        }
    }
    cout << "! " << res << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}