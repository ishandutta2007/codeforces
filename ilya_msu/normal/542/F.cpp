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
int N = 400;
//const int M = 10000000;
vector<vector<int> > q;
vector<vector<int> > res(105, vector<int>(1005, -1));
int get(int lev, int free) {
    if (lev == q.size())
        return 0;
    if (res[lev][free] != -1)
        return res[lev][free];
    int sum = 0;
    int ans = 0;
    for (int i = 0; (i <= q[lev].size()) && (i <= free); ++i) {
        ans = max(ans, sum + get(lev + 1, min((free - i) * 2, 1000)));
        if (i < q[lev].size())
            sum += q[lev][i];        
    }
    res[lev][free] = ans;
    return ans;
}

void solve() {
    int n, T;
    cin >> n >> T;
    q.resize(T);
    for (int i = 0; i < n; ++i) {
        int t, qq;
        cin >> t >> qq;
        int x = T - t;
        if (x >= 0)
            q[x].push_back(qq);
    }
    for (int i = 0; i < T; ++i) {
        sort(q[i].begin(), q[i].end());
        reverse(q[i].begin(), q[i].end());
    }
    cout << get(0, 1) << endl;    

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