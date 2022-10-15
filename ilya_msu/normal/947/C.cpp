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
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    multiset<int> b(p.begin(), p.end());
    vector<int> mask(30);
    for (int i = 0; i < 30; ++i) {
        mask[i] = ((1 << 30) - 1) & ((1 << 30) - (1 << i));
    }
    vector<int> tail(30);
    for (int i = 0; i < 30; ++i)
        tail[i] = (1 << i) - 1;
    int all = (1 << 30) - 1;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 29; j >= 0; --j) {
            auto it1 = b.lower_bound(x & mask[j]);
            auto it2 = b.upper_bound((x & mask[j]) | tail[j]);
            if (it2 == it1)
                x ^= (1 << j);
        }
        b.erase(b.find(x));
        cout << (x ^ a[i]) << " ";
    }
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