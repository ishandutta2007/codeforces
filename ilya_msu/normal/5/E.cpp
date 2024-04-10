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


ll solve(const vector<int>& a, int ok) {
    ll n = a.size();
    if (n == 0)
        return 0;
    ll res = n * (n - 1) / 2;
    vector<int> add(n, 0);
    int m = a[0];
    for (int i = 0; i < n; ++i) {
        m = max(m, a[i]);
        if (m == a[i])
            ++add[i];
    }
    m = a[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        m = max(m, a[i]);
        if (m == a[i])
            ++add[i];
        if (!ok)
            add[i] = min(1, add[i]);
        res += add[i];
    }
    vector<ll> next(n), nextEq(n, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        int last = -1;
        while (!(st.empty())) {
            if (a[st.top()] == a[i])
                ++nextEq[st.top()];
            if (a[st.top()] < a[i]) {
                next[st.top()] = i;
                if ((last != -1) && (a[st.top()] == a[last])) {
                    nextEq[st.top()] += nextEq[last];
                }
                last = st.top();
                st.pop();
            }
            else
                break;
        }
        st.push(i);
    }
    int last = -1;
    while (!(st.empty())) {
        next[st.top()] = n;
        if ((last != -1) && (a[st.top()] == a[last])) {
            nextEq[st.top()] += nextEq[last];
        }
        last = st.top();
        st.pop();
    }
    vector<ll> prev(n), prevEq(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        last = -1;
        while (!(st.empty())) {
            if (a[st.top()] == a[i]) {
                ++prevEq[st.top()];
            }
            if (a[st.top()] <= a[i]) {
                prev[st.top()] = i;
                if ((last != -1) && (a[st.top()] == a[last])) {
                    prevEq[st.top()] += prevEq[last];
                }
                last = st.top();
                st.pop();
            }
            else
                break;
        }
        st.push(i);
    }
    last = -1;
    while (!(st.empty())) {
        prev[st.top()] = -1;
        if ((last != -1) && (a[st.top()] == a[last])) {
            prevEq[st.top()] += prevEq[last];
        }
        last = st.top();
        st.pop();
    }
    for (int i = 0; i < n; ++i) {
        res -= (next[i] - i - 1) * (i - prev[i] - 1);// -nextEq[i] * prevEq[i];
        if (prev[i] != -1) {
            res -= next[i] - nextEq[i] - i - 1;
        }
        if (next[i] != n) {
            res -= i - prev[i] - 1;
        }
    }
    return res;

}


void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > m) {
            m = a[i];
            id = i;
        }
    }
    ll res = 0;
    vector<int> b;
    ll count = 1;
    for (int i = id + 1; (i % n)!= id; ++i) {
        if (i == n)
            i = 0;
        if (a[i] == m) {
            ++count;
            if (b.size() + 1 == a.size())
                res += solve(b, 0);
            else
                res += solve(b, 1);
            b.resize(0);
        }
        else {
            b.push_back(a[i]);
        }
    }
    if (b.size() + 1 == a.size())
        res += solve(b, 0);
    else
        res += solve(b, 1);
    res += count * (count - 1) / 2;
    cout << res << endl;

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