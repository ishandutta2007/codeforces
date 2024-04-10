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
//const int M = 10000000;

vector<ll> pref;
pll res(0, 1);
int num;
int med;

ll sum(int l, int r) {
    return pref[r + 1] - pref[l];
}

void get3(const vector<ll>& a, int n) {
    for (int i = 1; i + 1 < n; ++i) {
        int low = 1;
        int up = min(i, n - 1 - i) + 1;
        while (up - low > 1) {
            int m = (up + low) / 2;
            if ((a[i - m] + a[n - m]) * (2 * m - 1) > (sum(i - m + 1, i) + sum(n - m + 1, n - 1)) * 2)
                low = m;
            else
                up = m;
        }
        pll cur(sum(i - low, i) + sum(n - low, n - 1) - a[i] * (low * 2 + 1), low * 2 + 1);
        if (cur.first * res.second > cur.second * res.first) {
            res = cur;
            num = 2 * low + 1;
            med = i;
        }
    }
}

void get4(const vector<ll>& a, int n) {
    for (int i = 1; i + 2 < n; ++i) {
        int low = 1;
        int up = min(i, n - 2 - i) + 1;
        while (up - low > 1) {
            int m = (up + low) / 2;
            if ((a[i - m] + a[n - m]) * (2 * m) > (sum(i - m + 1, i + 1) + sum(n - m + 1, n - 1)) * 2)
                low = m;
            else
                up = m;
        }
        pll cur(sum(i - low, i + 1) + sum(n - low, n - 1) - a[i] * (low + 1) - a[i + 1] * (low + 1), low * 2 + 2);
        if (cur.first * res.second > cur.second * res.first) {
            res = cur;
            num = 2 * low + 2;
            med = i;
        }
        
    }

}


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n <= 2) {
        cout << 1 << endl;
        cout << a[0] << endl;
        return;
    }
    sort(a.begin(), a.end());
    pref.assign(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    get3(a, n);
    get4(a, n);
    if (res.first == 0) {
        cout << 1 << endl;
        cout << a[0] << endl;
        return;
    }
    if (num & 1) {
        cout << num << endl;
        for (int i = 0; i < num / 2; ++i)
            cout << a[med - num / 2 + i] << " ";
        cout << a[med];
        for (int i = 0; i < num / 2; ++i)
            cout << " " << a[n - num / 2 + i];
        cout << endl;
        return;
    }
    cout << num << endl;
    for (int i = 0; i + 1 < num / 2; ++i)
        cout << a[med - num / 2 + i + 1] << " ";
    cout << a[med] << " " << a[med + 1];
    for (int i = 0; i + 1 < num / 2; ++i)
        cout << " " << a[n - num / 2 + i + 1];
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