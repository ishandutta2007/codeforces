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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

deque<int> get(const string& s) {
    int n = s.size();
    deque<int> res;
    int x = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            ++x;
        else {
            res.push_back(x);
            x = 1;
        }
    }
    res.push_back(x);
    return res;
}


vector<int> v1, v2;

pii ch(deque<int>& a1, deque<int>& a2, int x, int y, int c = 1) {
    v1.clear();
    v2.clear();
    c = x ^ y ^ c;
    pii res(0, 0);
    for (int i = 0; i < x; ++i) {
        int z = a1.front();
        a1.pop_front();
        res.first += z;
        v1.push_back(z);
    }
    for (int i = 0; i < y; ++i) {
        int z = a2.front();
        a2.pop_front();
        res.second += z;
        v2.push_back(z);
    }
    if (!v1.empty()) {
        x = v1.back();
        v1.pop_back();
        if (a2.empty()) {
            a2.push_front(x);
        }
        else {
            if (c & 1) {
                int z = a2.front();
                a2.pop_front();
                x += z;
            }
            a2.push_front(x);
        }
    }

    if (!v2.empty()) {
        y = v2.back();
        v2.pop_back();
        if (a1.empty()) {
            a1.push_front(y);
        }
        else {
            if (c & 1) {
                int z = a1.front();
                a1.pop_front();
                y += z;
            }
            a1.push_front(y);
        }
    }

    
    for (int i = 0; i < v1.size(); ++i) {
        a2.push_front(v1[v1.size() - i - 1]);
    }
    for (int i = 0; i < v2.size(); ++i) {
        a1.push_front(v2[v2.size() - i - 1]);
    }
    return res;

}

pii trivCh(deque<int>& a1, deque<int>& a2) {
    int x = a1.front(), y = a2.front();
    a1.pop_front();
    a2.pop_front();
    if (a1.empty()) {
        a1.push_front(y);
    }
    else {
        int z = a1.front();
        a1.pop_front();
        a1.push_front(z + y);
    }
    if (a2.empty()) {
        a2.push_front(x);
    }
    else {
        int z = a2.front();
        a2.pop_front();
        a2.push_front(z + x);
    }
    return pii(x, y);

}


vector<vector<vector<int> > > d(10, vector<vector<int> >(10, vector<int>(2, 100)));
vector<vector<vector<pair<pii, int> > > > mv(10, vector<vector<pair<pii, int> > >(10, vector<pair<pii, int> >(2)));

void precalc() {
    d[1][1][1] = 0;
    bool ok = 1;
    while (ok) {
        ok = 0;
        for (int s = 3; s < 19; ++s) {
            for (int j = 1; j < s; ++j) {
                int i = s - j;
                if ((i >= 10) || (j >= 10))
                    continue;
                //cerr << i << " " << j << "\n";
                for (int i1 = 0; i1 <= i; ++i1) {
                    for (int j1 = 0; j1 <= j; ++j1) {
                        
                        int i2 = i - i1 + j1;
                        int j2 = j - j1 + i1;
                        for (int f = 0; f < 2; ++f) {
                            int c1 = 0, c2 = f;
                            int nc1, nc2;
                            int i3 = i2, j3 = j2;
                            if (((c1 ^ i1 ^ c2 ^ j1 ^ 1) % 2 == 0) && (j1 > 0) && (i1 < i))
                                --i3;
                            if (((c2 ^ j1 ^ c1 ^ i1 ^ 1) % 2 == 0) && (i1 > 0) && (j1 < j))
                                --j3;
                            if (j1 > 0) {
                                nc1 = c2;
                            }
                            else {
                                nc1 = (c1 ^ i1) & 1;
                            }
                            if (i1 > 0) {
                                nc2 = c1;
                            }
                            else {
                                nc2 = (c2 ^ j1) & 1;
                            }
                            int to = (nc1 ^ nc2) & 1;
                            if ((i3 > 0) && (i3 < 10) && (j3 > 0) && (j3 < 10)) {

                            if (d[i][j][f] > d[i3][j3][to] + 1) {
                                d[i][j][f] = d[i3][j3][to] + 1;
                                mv[i][j][f] = make_pair(pii(i1, j1), to);
                                ok = 1;
                            }
                            }
                        }
                    }
                }
            }
        }
    }

}

void solve() {
    string s, t;
    cin >> s >> t;
    deque<int> a1 = get(s), a2 = get(t);
    int n1 = a1.size(), n2 = a2.size();
    if (max(n1, n2) == 1) {
        cout << 0 << endl;
        return;
    }
    vector<pii> res;
    char c1 = s[0], c2 = t[0];
    precalc();
    
    while ((a1.size() >= 10) || (a2.size() >= 10)) {
        
        n1 = a1.size();
        n2 = a2.size();
        if (res.size() > 500000) {
            cout << n1 << " " << n2 << endl;
            return;
        }
        //cerr << n1 << " " << n2 << endl;
        if (n1 > n2 + 2) {
            int x = (n1 - n2) / 2 + 1, y = 1;
            if ((x % 2 == 0) ^ (s[0] == t[0]))
                ++x;
            res.push_back(ch(a1, a2, x, 1, (s[0] != t[0])));
        }
        else {
            if (n2 > n1 + 2) {
                int x = (n2 - n1) / 2 + 1; 
                if ((x % 2 == 0) ^ (s[0] == t[0]))
                    ++x;
                res.push_back(ch(a1, a2, 1, x, (s[0] != t[0])));
            }        
            else {
                
                if (s[0] == t[0]) {
                    if (n1 < n2) {
                        res.push_back(ch(a1, a2, 1, 2, 0));
                    }
                    else {
                        res.push_back(ch(a1, a2, 2, 1, 0));
                    }
                }
                else {
                    res.push_back(trivCh(a1, a2));
                }
            }
        }
    }
    int f = (c1 != c2);
    while ((a1.size() > 1) || (a2.size() > 1)) {
        //cerr << a1.size() << " " << a2.size() << " " << f << "\n";
        pair<pii, int> cr = mv[a1.size()][a2.size()][f];
        //cerr << cr.first.first << " " << cr.first.second << "\n";
        res.push_back(ch(a1, a2, cr.first.first, cr.first.second, f));
        f = cr.second;
        if (res.size() > 500000) {
            cout << 123 << endl;
            return;
        }

    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << "\n";
    }
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