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

void tr(vector<int>& a) {
    vector<int> b(a);
    sort(b.begin(), b.end());
    map<int, int> m;
    m[b[0]] = 0;
    int sz = 1;
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] == b[i - 1])
            continue;
        m[b[i]] = sz;
        ++sz;
    }
    for (int i = 0; i < a.size(); ++i) {
        a[i] = m[a[i]];
    }
}

struct fenvick {
    int n;
    vector<int> a;
    fenvick(int nn) {
        n = nn;
        a.assign(n, 0);
    }
    void inc(int i, int x) {
        for (; i < n; i = i | (i + 1))
            a[i] += x;
    }
    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += a[r];
        return res;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

};

struct query {
    int r, up, sign, k;
};

bool comp(const query& a, const query& b) {
    return (a.r < b.r);

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    tr(a);
    vector<int> res(n, 0);
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            ++res[1];
    N = min(n, N);
    for (int i = 2; i <= n; ++i) {
        for (int k = 2; k < N; ++k) {
            int p = (i + k - 2) / k;
            if (a[i - 1] < a[p - 1])
                ++res[k];
        }
    }
    vector<query> q;
    for (int k = N; k < n; ++k) {
        for (int i = 1; i * k - k + 2 <= n; ++i) {
            query qq1, qq2;
            qq1.k = k;
            qq2.k = k;
            qq1.sign = 1;
            qq2.sign = -1;
            qq1.up = a[i - 1];
            qq2.up = a[i - 1];
            int l = i * k - k + 2, r = i * k + 1;
            qq2.r = l - 1;
            qq1.r = min(r, n);
            q.push_back(qq1);
            q.push_back(qq2);
        }
    }
    sort(q.begin(), q.end(), comp);
    int add = 0;
    fenvick tr(n + 1);
    for (int i = 0; i < q.size(); ++i) {
        while (add < q[i].r) {
            tr.inc(a[add], 1);
            ++add;
        }
        int x = tr.sum(0, q[i].up - 1);
        res[q[i].k] += q[i].sign * x;
    }
    for (int i = 1; i < n; ++i)
        cout << res[i] << " ";
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