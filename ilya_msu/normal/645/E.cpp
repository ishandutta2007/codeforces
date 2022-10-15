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



void solve() {
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    vector<int> last(k, -1);
    for (int i = 0; i < t.size(); ++i) {
        last[t[i] - 'a'] = i;
    }
    vector<ll> d(t.size() + n + 1);
    d[0] = 1;
    vector<int> prev(k, -1);
    for (int i = 1; i <= t.size(); ++i) {
        if (prev[t[i - 1] - 'a'] == -1)
            d[i] = (2 * d[i - 1]) % mod;
        else
            d[i] = (2 * d[i - 1] - d[prev[t[i - 1] - 'a'] - 1] + mod) % mod;
        prev[t[i - 1] - 'a'] = i;
    }
    vector<pii> ord(k);
    for (int i = 0; i < k; ++i) {
        ord[i] = pii(last[i], i);
    }
    sort(ord.begin(), ord.end());
    deque<int> q;
    for (int i = 0; i < k; ++i)
        q.push_back(ord[i].second);
    for (int i = t.size() + 1; i <= t.size() + n; ++i) {
        int v = q.front();
        if (prev[v] == -1)
            d[i] = (2 * d[i - 1]) % mod;
        else
            d[i] = (2 * d[i - 1] - d[prev[v] - 1] + mod) % mod;
        prev[v] = i;
        q.pop_front();
        q.push_back(v);
    }
    cout << d[t.size() + n] << endl;
    
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