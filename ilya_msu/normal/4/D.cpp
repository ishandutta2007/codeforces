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


struct env {
    int w, h, id;
};

bool operator<(const env& a, const env& b) {
    return pii(a.w, -a.h) < pii(b.w, -b.h);
}

void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<env> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].w >> a[i].h;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end());
    vector<int> d(n, 0), p(n, -1);
    int res = 0;
    int end = -1;
    for (int i = 0; i < n; ++i) {
        if (!((a[i].h > h) && (a[i].w > w)))
            continue;
        d[i] = 1;
        p[i] = i;
        for (int j = 0; j < i; ++j) {
            if (a[i].h > a[j].h) {
                if (d[j] >= d[i]) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }
        if (d[i] > res) {
            res = d[i];
            end = i;
        }
    }
    vector<int> ans;
    for (int i = 0; i < res; ++i) {
        ans.push_back(a[end].id);
        end = p[end];
    }
    reverse(ans.begin(), ans.end());
    cout << res << endl;
    for (int i = 0; i < res; ++i)
        cout << ans[i] << " ";
    cout << endl;

}


#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();




#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}