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
//#include<unordered_map>




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
const ll N = 1000000;
//const int M = 10000000;


void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    vector<int> q(n);
    vector<double> dq(n);
    double cur = 1;
    for (int i = 0; i < n; ++i) {
        q[i] = 100 - p[i];
        dq[i] = 0.01 * q[i];
        cur *= (1.0 - dq[i]); 
    }
    vector<double> curq = dq;
    double res = n + 1 - cur;
    vector<int> k(n, 1);
    priority_queue<pair<double, int> > qu;
    for (int i = 0; i < n; ++i) {
        qu.push(make_pair(0.01 * p[i] * curq[i] / (1 - curq[i]), i));
    }
    for (int i = 0; i < 1000000; ++i) {
        //cerr << i << endl;
        pair<double, int> ver = qu.top();
        qu.pop();
        int ind = ver.second;
        cur *= (ver.first + 1);
        /*if (cur + 1e-9 > 1.)
            break;*/
        res += 1 - cur;
        ++k[ind];
        curq[ind] *= dq[ind];
        qu.push(make_pair(0.01 * p[ind] * curq[ind] / (1 - curq[ind]), ind));
    }
    printf("%0.12f\n", res);

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