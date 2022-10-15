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
//const ll mod = 1000 * 1000 * 1000 + 7;
const ll mod = 1000 * 1000 * 1000 + 7;

void check(const string& res, const string& s, const string& a, const string& b) {
    int k = res.size();
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char c = res[s[i] - 'a'];
        if (c == a[i])
            continue;
        if (c < a[i]) {
            cout << "NO\n";
            return;
        }
        break;
    }
    for (int i = 0; i < n; ++i) {
        char c = res[s[i] - 'a'];
        if (c == b[i])
            continue;
        if (c > b[i]) {
            cout << "NO\n";
            return;
        }
        break;
    }
    cout << "YES\n";
    cout << res << "\n";

}


void fin(string& res, int k, vector<int>& used, const string& s, const string& a, const string& b) {
    int j = 0;
    for (int i = 0; i < k; ++i) {
        if (res[i] != ' ')
            continue;
        while ((j < k) && (used[j]))
            ++j;
        if (j == k) {
            cout << "NO\n";
            return;
        }
        res[i] = (char)('a' + j);
        used[j] = 1;
    }
    check(res, s, a, b);
    return;
}

void fin1(string& res, int k, vector<int>& used, const string& s, const string& a, const string& b, int id) {
    int n = s.size();
    int j = 0;
    for (int i = id; i < n; ++i) {
        if (res[s[i] - 'a'] == ' ') {
            while ((j < k) && (used[j])) {
                ++j;
            }
            if (j == k) {
                cout << "NO\n";
                return;
            }
            res[s[i] - 'a'] = (char)('a' + j);
            used[j] = 1;
        }
        if (res[s[i] - 'a'] > b[i]) {
            cout << "NO\n";
            return;
        }
        if (res[s[i] - 'a'] < b[i]) {
            fin(res, k, used, s, a, b);
            return;
        }
    }
    fin(res, k, used, s, a, b);
    return;
}

bool fin21(string res, int k, vector<int> used, const string& s, const string& a, const string& b, int id) {
    int n = s.size();
    int j = 0;
    for (int i = id; i < n; ++i) {
        if (res[s[i] - 'a'] == ' ') {
            while ((j < k) && (used[j])) {
                ++j;
            }
            if (j == k) {
                //cout << "NO\n";
                return 0;
            }
            res[s[i] - 'a'] = (char)('a' + j);
            used[j] = 1;
        }
        if (res[s[i] - 'a'] > b[i]) {
            //cout << "NO\n";
            return 0;
        }
        if (res[s[i] - 'a'] < b[i]) {
            //fin(res, k, used, s, a, b);
            return 1;
        }
    }
    //fin(res, k, used, s, a, b);
    return 1;
}


void fin2(string& res, int k, vector<int>& used, const string& s, const string& a, const string& b, int id) {
    int n = s.size();
    int j = k - 1;
    for (int i = id; i < n; ++i) {
        if (res[s[i] - 'a'] == ' ') {
            while ((j > -1) && (used[j])) {
                --j;
            }
            if (j == -1) {
                cout << "NO\n";
                return;
            }
            res[s[i] - 'a'] = (char)('a' + j);
            used[j] = 1;
        }
        if (res[s[i] - 'a'] < a[i]) {
            cout << "NO\n";
            return;
        }
        if (res[s[i] - 'a'] > a[i]) {
            fin(res, k, used, s, a, b);
            return;
        }
    }
    fin(res, k, used, s, a, b);
    return;
}

bool fin22(string res, int k, vector<int> used, const string& s, const string& a, const string& b, int id) {
    int n = s.size();
    int j = k - 1;
    for (int i = id; i < n; ++i) {
        if (res[s[i] - 'a'] == ' ') {
            while ((j > -1) && (used[j])) {
                --j;
            }
            if (j == -1) {
                //cout << "NO\n";
                return 0;
            }
            res[s[i] - 'a'] = (char)('a' + j);
            used[j] = 1;
        }
        if (res[s[i] - 'a'] < a[i]) {
            //cout << "NO\n";
            return 0;
        }
        if (res[s[i] - 'a'] > a[i]) {
            //fin(res, k, used, s, a, b);
            return 1;
        }
    }
    //fin(res, k, used, s, a, b);
    return 1;
}




void solve1() {
    int k;
    string s, a, b;
    cin >> k >> s >> a >> b;
    int n = s.size();
    int id = 0;
    string res;
    res.assign(k, ' ');
    vector<int> used(k, 0);
    while ((id < n) && (a[id] == b[id])) {
        if (res[s[id] - 'a'] == a[id]) {
            ++id;
            continue;
        }
        if ((res[s[id] - 'a'] != ' ') || (used[a[id] - 'a'])) {
            cout << "NO\n";
            return;
        }
        res[s[id] - 'a'] = a[id];
        used[a[id] - 'a'] = 1;
        ++id;
    }
    if (id == n) {
        fin(res, k, used, s, a, b);
        return;
    }
    if (res[s[id] - 'a'] != ' ') {
        if ((res[s[id] - 'a'] < a[id]) || (res[s[id] - 'a'] > b[id])) {
            cout << "NO\n";
            return;
        }
        if ((res[s[id] - 'a'] > a[id]) && (res[s[id] - 'a'] < b[id])) {
            fin(res, k, used, s, a, b);
            return;
        }
        if (res[s[id] - 'a'] > a[id]) {
            fin1(res, k, used, s, a, b, id + 1);
            return;
        }
        fin2(res, k, used, s, a, b, id + 1);
        return;
    }
    for (int i = a[id] - 'a' + 1; i < (int)(b[id] - 'a'); ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            res[s[id] - 'a'] = (char)('a' + i);
            fin(res, k, used, s, a, b);
            return;
        }
    }

    if (used[a[id] - 'a'] == 0) {
        used[a[id] - 'a'] = 1;
        res[s[id] - 'a'] = a[id];
        if (fin22(res, k, used, s, a, b, id + 1)) {
            fin2(res, k, used, s, a, b, id + 1);
            return;
        }
        else {
            used[a[id] - 'a'] = 0;
            res[s[id] - 'a'] = ' ';
        }
    }
    if (used[b[id] - 'a'] == 0) {
        used[b[id] - 'a'] = 1;
        res[s[id] - 'a'] = b[id];
        if (fin21(res, k, used, s, a, b, id + 1)) {
            fin1(res, k, used, s, a, b, id + 1);
            return;
        }
        else {
            used[b[id] - 'a'] = 0;
            res[s[id] - 'a'] = ' ';
        }
    }
    cout << "NO\n";
    return;




}

void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve1();
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