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
#include<iterator>
#include<random>





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
const ll mod = 998244353;
    

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> res(n);
    vector<int> used(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (used[a[i]])
            res[i] = -1;
        else {
            res[i] = a[i];
            used[a[i]] = 1;
            ++ans;
        }
    }
    int id = 0;
    for (int i = 0; i < n; ++i) {
        if (res[i] == -1) {
            while (used[id]) ++id;
            res[i] = id;
            used[id] = 1;
        }
    }
    vector<int> b;
    for (int i = 0; i < n; ++i)
        if (res[i] == i)
            b.push_back(i);
    if (b.size() > 1) {
        for (int i = 0; i < b.size(); ++i) {
            int j = (i + 1) % b.size();
            res[b[i]] = b[j];
        }
    }
    else {
        if (b.size() == 1) {
            int x = b[0];
            int y = a[x];
            int p = 0;
            while (res[p] != y)
                ++p;
            res[p] = x;
            res[x] = a[x];
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " ";
    }
    cout << "\n";
}



//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
int t;
cin >> t;
for (int i = 0; i < t; ++i)
solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}