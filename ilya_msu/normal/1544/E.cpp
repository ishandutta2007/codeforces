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
    

string solve(string s) {
    int n = s.size();
    vector<int> c(26, 0);
    int oneLet = 1;
    for (int i = 0; i < n; ++i) {
        ++c[s[i] - 'a'];
        if (s[i] != s[0])
            oneLet = 0;
    }
    if (oneLet) {
        return s;
    }
    for (int i = 0; i < 26; ++i) {
        if (c[i] == 1) {
            string res = "";
            res += (char)('a' + i);
            --c[i];
            for (int j = 0; j < 26; ++j) {
                for (int l = 0; l < c[j]; ++l) {
                    res += (char)('a' + j);
                }
            }
            return res;
        }
    }
    vector<pair<char, int> > v;
    for (int i = 0; i < 26; ++i) {
        if (c[i] > 0)
        v.push_back(make_pair('a' + i, c[i]));
    }
    string res = "";
    if (v[0].second * 2 - 2 <= n) {
        string s1 = "";
        for (int i = 1; i < v.size(); ++i) {
            for (int j = 0; j < v[i].second; ++j)
                s1 += v[i].first;
        }
        res += v[0].first;
        res += v[0].first;
        for (int i = 0; i < v[0].second - 2; ++i) {
            res += s1[i];
            res += v[0].first;
        }
        for (int i = v[0].second - 2; i < s1.size(); ++i) {
            res += s1[i];
        }
        return res;
    }
    if (v.size() == 2) {
        res += v[0].first;
        for (int i = 0; i < v[1].second; ++i) {
            res += v[1].first;
        }
        for (int i = 1; i < v[0].second; ++i) {
            res += v[0].first;
        }
        return res;
    }
    res += v[0].first;
    res += v[1].first;
    --v[1].second;
    for (int i = 1; i < v[0].second; ++i) {
        res += v[0].first;
    }
    res += v[2].first;
    --v[2].second;
    for (int i = 1; i < v.size(); ++i) {
        for (int j = 0; j < v[i].second; ++j) {
            res += v[i].first;
        }
    }
    return res;
    
}



//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
int t;
cin >> t;
for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
}

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}