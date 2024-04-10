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
    vector<int> msk1(10000, INF), msk2(10000, INF);
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    msk1[b[0]] = a[0] - 1;
    int c[4];
    for (int i = 1; i < n; ++i) {
        for (int m = 0; m < msk1.size(); ++m) {
            if (msk1[m] == INF)
                continue;
            int x = m;
            int id = 0;
            while (x > 0) {
                c[id] = x % 10;
                x /= 10;
                ++id;
            }
            for (int l = 1; l <= min(a[i], a[i - 1]); ++l) {
                for (int r = max(a[i], a[i - 1]); r < 10; ++r) {
                    int cc[4];
                    int id2 = 0;
                    for (int j = 0; j < id; ++j) {
                        if ((c[j] < l) || (c[j] > r)) {
                            cc[id2] = c[j];
                            ++id2;
                        }
                    }
                    if (id2 == 4)
                        continue;
                    cc[id2] = b[i];
                    sort(cc, cc + id2 + 1);
                    int y = 0;
                    int mn = 1;
                    for (int j = 0; j < id2 + 1; ++j) {
                        y = y + mn * cc[j];
                        mn *= 10;
                    }
                    msk2[y] = min(msk2[y], msk1[m] + (r - l) * 2 - abs(a[i] - a[i - 1]));
                }
            }
        }
        swap(msk1, msk2);
        msk2.assign(10000, INF);
    }
    int res = INF;
    for (int m = 0; m < msk1.size(); ++m) {
        if (msk1[m] == INF)
            continue;
        int x = m;
        int id = 0;
        int l = a[n - 1], r = a[n - 1];
        while (x > 0) {
            c[id] = x % 10;
            l = min(c[id], l);
            r = max(r, c[id]);
            x /= 10;
            ++id;
        }
        res = min(res, msk1[m] + r - l + min(r - a[n - 1], a[n - 1] - l));
    }
    cout << res + 2 * n << endl;
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