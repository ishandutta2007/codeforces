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
const ll mod = 1000000007;


ll test(ll qq) {
    vector<int> p;
    set<int> s;
    for (int i = 0; i < 120; ++i) {
        int a = 1;
        while (s.find(a) != s.end())
            ++a;
        int b = a + 1;
        while ((s.find(b) != s.end()) || (s.find(a ^ b) != s.end()))
            ++b;
        p.push_back(a);
        p.push_back(b);
        p.push_back(a ^ b);
        s.insert(a);
        s.insert(b);
        s.insert(a ^ b);
        
    }
    /*for (int i = 0; i < p.size(); i += 3) {
        cout << i + 1 << ":" << p[i] << endl;
        cout << i + 2 << ":" << p[i+1] << endl;
        cout << i + 3 << ":" << p[i+2] << endl;
        cout << endl;

    }*/
    if (qq - 1 < p.size()) {
        return p[qq - 1];
    }
    else 
        return -1;

}

void solve() {
    int t;
    cin >> t;
    vector<ll> d(31);
    d[0] = 1;
    for (int i = 1; i < d.size(); ++i) {
        d[i] = d[i - 1] * 4;
    }
    vector<ll> p(31);
    p[0] = d[0];
    for (int i = 1; i < p.size(); ++i) {
        p[i] = p[i - 1] + d[i];
    }
    for (int tt = 0; tt < t; ++tt) {
        ll n;
        cin >> n;
        if (n <= 4) {
            cout << n << "\n";
            continue;
        }
        --n;
        ll q = n / 3 + 1;
        int r = n % 3;
        int id = 0;
        while (q > p[id]) ++id;
        ll a = q - p[id - 1] + 3 * p[id - 1];
        //cerr << a << endl;
        ll qq = q - p[id - 1];
        //cout << qq << endl;
        //cout << a << endl;
        int id2 = 0;
        while (qq > d[id2]) ++id2;
        //cerr << d[id2] << endl;
        --qq;
        ll b = 0;
        ll ml = 1;
        while (qq) {
            int qr = qq % 4;
            ll add = 0;
            if (qr == 1)
                add = 2;
            if (qr == 2)
                add = 3;
            if (qr == 3)
                add = 1;
            b += ml * add;
            ml *= 4;
            qq /= 4;
        }
        b += d[id] * 2;
        ll c = a ^ b;
        //cerr << a << " " << b << " " << c << endl;
        if (r == 0)
            cout << a << "\n";
        if (r == 1)
            cout << b << "\n";
        if (r == 2)
            cout << c << "\n";
        /*ll ts = test(n + 1);
        if (ts != -1)   
            cout << "test " << ts << endl;*/
    }
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    solve();
    //test();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}