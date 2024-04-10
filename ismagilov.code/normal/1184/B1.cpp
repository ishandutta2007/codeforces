#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

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

signed main() {
   int s, b;
   cin >> s >> b;
   vc<int> a(s);
   cin >> a;
   vc<pr<int, int>> x(b);
   cin >> x;
   x.pb({0, 0});
   int maxi = 0;
   sort(all(x));
   for (auto &v : x){
       v.sc = maxi += v.sc;
   }
   for (int i = 0; i < s; i++){
      cout << x[(lower_bound(all(x), mp(a[i], INF)) - x.begin() - 1)].sc << ' ';
   }

}