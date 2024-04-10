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
const int N = 5000;
//const int M = 10000000;




ll get(ll a, ll b, ll d) {
    ll res = 0;
    for (int i = 0; i <= d; ++i) {
        ll aa = a + i;
        ll x = min(aa - b, d - i);
        if (x < 0)
            continue;
        res += (x + 1) * (x + 2) / 2;
    }
    return res;
}

ll brute(ll a, ll b, ll c, ll l) {
    ll res = 0;
    for (int i1 = 0; i1 <= l; ++i1)
        for (int i2 = 0; i2 + i1 <= l; ++i2)
            for (int i3 = 0; i3 + i2 + i1 <= l; ++i3) {
                int aa = a + i1, bb = b + i2, cc = c + i3;
                if ((aa + bb > cc) && (aa + cc > bb) && (bb + cc > aa))
                    ++res;
            }
    return res;
                
}

void gen(ll& a, ll& b, ll& c, ll& l) {
    a = rand() % 200 + 1;
    b = rand() % 200 + 1;
    c = rand() % 200 + 1;
    l = rand() % 200;

}

void solve() {
    ll a, b, c, l;
    cin >> a >> b >> c >> l;
    //int count = 0;
    //while (true) {
        //gen(a, b, c, l);
        ll res1 = 0;

        ll aa = get(a, b + c, l);
        ll bb = get(b, a + c, l);
        ll cc = get(c, b + a, l);
        res1 += aa + bb + cc;

        res1 = (l + 3) * (l + 2) * (l + 1) / 6 - res1;
        /*ll res2 = brute(a, b, c, l);
        if (res1 != res2) {
            cout << a << " " << b << " " << c << " " << l << endl;
            cout << res1 << endl;
            cout << res2 << endl;

            return;
        }
        else
            ++count;
        if (count % 1000 == 0)
            cout << count << endl;
    }*/
    cout << res1 << endl;    
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