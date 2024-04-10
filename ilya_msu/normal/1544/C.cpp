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
    vector<int> c1(101, 0), c2(101, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++c1[x];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++c2[x];
    }
    int low = -1, up = n;
    while (up - low > 1) {
        int mid = (up + low) / 2;
        int m = (n + mid);
        int k = m - m / 4;
        int r1 = 0, r2 = 0;
        c1[100] += mid;
        c2[0] += mid;
        int s1 = 0, s2 = 0;
        for (int i = 100;  i >= 0; --i) {
            r1 += min(c1[i], k - s1) * i;
            r2 += min(c2[i], k - s2) * i;
            s1 += min(c1[i], k - s1);
            s2 += min(c2[i], k - s2);
        }
        c1[100] -= mid;
        c2[0] -= mid;
        if (r1 >= r2) 
            up = mid;
        else 
            low = mid;
    }
    cout << up << "\n";
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