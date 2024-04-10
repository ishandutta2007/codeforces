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

void solve0(int n, vector<int>& a) {
    int k = n / 2;
    vector<int> res(n, 0);
    int x = 0;
    for (int i = 0; i < k; ++i) {
        res[2 * i] = max(max(x, a[k - i - 1]), a[k + i]);
        x = res[2 * i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = a[i];
        if ((i > 0) && (i + 1 < n))
            ans[i] = min(ans[i], max(a[i - 1], a[i + 1]));
    }
    x = 0;
    for (int i = 0; i < k; ++i) {
        res[2 * i + 1] = max(x, max(ans[k - i - 1], ans[k + i]));
        x = res[2 * i + 1];
    }
    for (int i = 0; i < n; ++i)
        res[n - 1] = max(res[n - 1], a[i]);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
}

void solve1(int n, vector<int>& a) {
    int k = n / 2;
    vector<int> res(n, 0);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = a[i];
        if ((i > 0) && (i + 1 < n))
            ans[i] = min(ans[i], max(a[i - 1], a[i + 1]));
    }
    res[0] = ans[k];
    for (int i = 1; i <= k; ++i) {
        res[2 * i] = max(res[2 * i - 2], max(ans[k - i], ans[k + i]));
    }
    
    int x = a[k];
    for (int i = 0; i < k; ++i) {
        res[2 * i + 1] = max(x, max(a[k - i - 1], a[k + i + 1]));
        x = res[2 * i + 1];
    }
    for (int i = 0; i < n; ++i)
        res[n - 1] = max(res[n - 1], a[i]);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;


}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n % 2 == 0) {
        solve0(n, a);
    }
    else
        solve1(n, a);
  
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