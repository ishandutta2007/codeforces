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
const int N = 500;
//const int M = 10000000;



void solve() {
    int n, k;
    cin >> n >> k;
    int a0 = 0, a1 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x & 1)
            ++a1;
        else
            ++a0;
    }
    if (k == n) {
        if (a1 % 2 == 0)
            cout << "Daenerys" << endl;
        else
            cout << "Stannis" << endl;
        return;
    }
    if (k == 0) {
        cout << "Daenerys" << endl;
        return;

    }
    int h = n - k;
    if (h % 2 == 0) {
        if ((k & 1) && (h / 2 >= a0))
            cout << "Stannis" << endl;
        else
            cout << "Daenerys" << endl;
        return;
    }
    if ((h - 1) / 2 >= a1) {
        cout << "Daenerys" << endl;
        return;
    }
    if ((h - 1) / 2 >= a0) {
        if (k % 2 == 0) {
            cout << "Daenerys" << endl;
            return;
        }
    }
    cout << "Stannis" << endl;


    
}

//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
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