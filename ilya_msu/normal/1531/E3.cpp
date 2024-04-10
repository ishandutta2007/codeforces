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
#include<deque>
#include<cmath>
#include<iterator>
#include<random>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;
    
string s;
vector<int> len;
vector<int> a;
vector<int> ac;

int merge(int b, int e, int sb) {
    int n = e - b;
    if (n <= 1)
        return 0;
    int mid = (b + e) / 2;    
    int sz1 = merge(b, mid, sb);
    if (sz1 == INF)
        return INF;
    int sz2 = merge(mid, e, sb + sz1);
    if (sz2 == INF)
        return INF;
    int st = sb + sz1 + sz2;
    int i = st, i1 = b, i2 = mid, k = b;
    for ( ; (i1 < mid) && (i2 < e); ++i) {
        if (i >= s.size())
            return INF;
        if (s[i] == '0') {
            ac[k] = a[i1];
            ++i1;
            ++k;
        }
        else {
            ac[k] = a[i2];
            ++k;
            ++i2;
        }
    }
    for (int j = i1; j < mid; ++j) {
        ac[k] = a[j];
        ++k;
    }
    for (int j = i2; j < e; ++j) {
        ac[k] = a[j];
        ++k;
    }
    for (int j = b; j < e; ++j)
        a[j] = ac[j];
    return i - sb;
}

vector<int> solve() {
    int m = s.size();
    int low = 1, up = 100000 + 5;
    while (up - low > 1) {
        int n = (up + low) / 2;
        a.resize(n);
        ac.resize(n);
        for (int i = 0; i < n; ++i) a[i] = i;
        int sz = merge(0, n, 0);
        if (sz == m) {
            vector<int> p(n);
            for (int i = 0; i < n; ++i) {
                p[a[i]] = i + 1;
            }
            return p;
        }
        if (sz > m) {
            up = n;
        }
        else {
            low = n;
        }
    }
    /*for (int i = 1; ; ++i) {
        int n = low;
        if (i & 1) {
            n += i / 2;
        }
        else {
            n -= i / 2;
        }
        if (n < 1)
            continue;
        a.resize(n);
        ac.resize(n);
        for (int i = 0; i < n; ++i) a[i] = i;
        int sz = merge(0, n, 0);
        if (sz == m) {
            vector<int> p(n);
            for (int i = 0; i < n; ++i) {
                p[a[i]] = i + 1;
            }
            return p;
        }
    }*/
    return vector<int>(1, -1);

}


void mergeSort(int l, int r) {
    if (r - l <= 1)
      return;
    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m, r);
    int i = l, j = m, k = l;
    while ((i < m) && (j < r)) {
        if (a[i] < a[j]) {
            s += '0';
            ac[k] = a[i];
            ++i;
        }
        else {
            s += '1';
            ac[k] = a[j];
            ++j;
        }
        ++k;
    }
    while (i < m) {
        ac[k] = a[i];
        ++i;
        ++k;
    }
    while (j < r) {
        ac[k] = a[j];
        ++j; 
        ++k;
    }
    for (int i = l; i < r; ++i)
        a[i] = ac[i];
    return;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

/*
int id = 0;
while (true) {
    ++id;
    int n = 1000;
    a.resize(n);
    ac.resize(n);
    for (int i = 0; i < n; ++i)
        a[i] = i;
    shuffle(a.begin(), a.end(), std::default_random_engine(143 + id));
    vector<int> copy_a(a);
    s = "";
    mergeSort(0, n);
    vector<int> res = solve();
    string olds = s;
    s = "";
    a = res;
    mergeSort(0, res.size());
    int ok = 1;
    sort(res.begin(), res.end());
    for (int i = 1; i < res.size(); ++i) {
        if (res[i] == res[i - 1])
            ok = 0;
    }
    if ((s == olds) && (ok)) {
        //if (id % 10000 == 0)
        cout << ++id << " " << s << " OK\n";
    }
    else {
        for (int i = 0; i < n; ++i) {
            cout << copy_a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
        break;

    }
}*/

cin >> s;

vector<int> res = solve();
cout << res.size() << endl;
for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
}
cout << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}