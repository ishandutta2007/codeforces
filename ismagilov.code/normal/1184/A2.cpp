#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCjjjjjjjC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;

template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

bool checks(string s, int k){
    for (int i = 0; i < k; i++){
        int mems = 0;
        for (int j = i; j < len(s); j += k){
            if (s[j] == '1'){
                mems ^= 1;
            }
        }
        if (mems == 1){
            return 0;
        }
    }
    return 1;
}

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mems = 0;
    int ans = 1;
    for (auto v : s) {
        if (v == '1') {
            ans = 0;
        }
        mems = mems ^ (v - '0');
    }
    vc<bool> an(n, 0);
    an[0] = ans;
    ans = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0){
            an[i] = checks(s, i);
        }
        else{
            an[i] = an[gcd(i, n)];
        }
    }
    for (int i = 0; i < n; i++){
        ans += an[i];
    }
    cout << ans;
}