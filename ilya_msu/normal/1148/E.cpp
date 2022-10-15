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
#include <random>
#include <chrono>


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
    cin >> n;
    vector<pii> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += s[i].first;
        sum2 += t[i];
    }
    if (sum1 != sum2) {
        cout << "NO\n";
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = t[i] - s[i].first;
    }
    vector<ll> sm(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sm[i + 1] = sm[i] + a[i];
        if (sm[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> st;
    cout << "YES\n";
    vector<int> id1, id2, d;
    for (int i = 0; i < n; ++i) {
        //cerr << i << " " << a[i] << endl;
        if (a[i] > 0) {
            st.push_back(i);
            continue;
        }
        while (a[i] < 0) {
            int v = st.back();
            int x = min(a[v], -a[i]);
            //cerr << x << endl;
            id1.push_back(s[v].second);
            id2.push_back(s[i].second);
            d.push_back(x);
            a[i] += x;
            a[v] -= x;
            if (a[v] == 0)
                st.pop_back();
        }
    }
    cout << id1.size() << endl;
    for (int i = 0; i < id1.size(); ++i) {
        cout << id1[i] << " " << id2[i] << " " << d[i] << "\n";
    }



    
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

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