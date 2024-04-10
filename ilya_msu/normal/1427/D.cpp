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
//#include<atcoder/dsu>


//using namespace atcoder;
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

vector<int> move(vector<int> a, vector<int> m) {
    
    
    vector<int> p(m.size() + 1, 0);
    for (int i = 1; i < p.size(); ++i) {
        p[i] = p[i - 1] + m[i - 1];
    }
    
    vector<int> b(a.size());
    int id = 0;
    for (int i = p.size() - 2; i >= 0; --i) {
        for (int j = p[i]; j < p[i + 1]; ++j) {
            b[id] = a[j];
            ++id;
        }
    }
    
    return b;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int> > moves;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1)
            p = i;
    }
    if ((p != 0) && (p != (n - 1))) {
        //cerr << "!" << p << endl;
        vector<int> x;
        if (n & 1) 
            x = {p, n - p};
        else 
            x = {p + 1, n - p - 1};
        moves.push_back(x);
        a = move(a, x);
    }
    /*cerr << 1 << ":";
    for (int j = 0; j < n; ++j) {
        cerr << a[j] << " ";
    }
    cerr << endl;*/
    for (int i = 2; i <= n; ++i) {
        int p = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == i)
                p = j;
        }
        //cerr << p << endl;
        if (a[0] == 1) {
            vector<int> x(i - 1, 1);
            x.push_back(p - (i - 2));
            int s = i - 1 + p - i + 2;
            if (s < n)
                x.push_back(n - s);
            moves.push_back(x);
            a = move(a, x);
        }
        else {
            vector<int> x(i - 1, 1);
            int pp = n - 1 - p;
            x.push_back(pp - i + 2);
            int s = i - 1 + pp - i + 2;
            if (s < n)
                x.push_back(n - s);
            reverse(x.begin(), x.end());
            moves.push_back(x);
            a = move(a, x);
        }
        /*cerr << i << ":";
        for (int j = 0; j < n; ++j) {
            cerr << a[j] << " ";
        }
        cerr << endl;*/
    }
    if (a[0] != 1) {
        vector<int> x(n, 1);
        moves.push_back(x);
        a = move(a, x);
    }
    /*for (int i = 0; i < n; ++i) {
        cerr << a[i] << " ";
    }
    cerr << endl;*/
    cout << moves.size() << "\n";
    for (int i = 0; i < moves.size(); ++i) {
        cout << moves[i].size() << " ";
        for (int j = 0; j < moves[i].size(); ++j) {
            cout << moves[i][j] << " ";
        }
        cout << "\n";
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