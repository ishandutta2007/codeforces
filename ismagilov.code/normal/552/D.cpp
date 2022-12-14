/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

                                         /*..         ....
                                    ..',,'..............''...'''.','..
                                  .';'..                          ..',,'.
                                 .'..                                 .';,.
                                .'.              .:ol;.                 .';.
                                ..              .cO00k:.                  .,.
                               ..          .'...;k00Od'                   .'.
                              ...        .;xOkxdk00Od,                    ...
                             ...        .,x0000000Od;.                     ..
                             .'         .cO00OOOOOOd;'...                 ...
                            .'.          .;lxkOOOO00Okkxo:.               .'.
                           .'.             .cxOOOOO000000Ol.              .'.
                          .'.             .ck00OOd::oxOOOOl.              .,.
                          ''...,;''''''''':kKK0Od,. ..:xOo'               .,.
                         ';,;;;:,..........;lxOx:.    .';'               .''
                        'cc;..               .,;:,..                     ...
                       ,oc.       ..........    .',:;,..                 ...
                      'o:.     .,;;;,,,,;;;;;'.    ..,;;,..              ...
                      ';.      ...         .,::.       .,::'.            .'.
                      ..                     .',.        ..;;'.         ...
                     ..          .',,;;,'.                  ':;'.       .,.
                    .,::;,.        .......                   .';:'.    .,,.
                    .;dOK0x;.                         .        .':;.   .,.
                    ...,cdxdl;.              ..,;;;cloddoc;.     .,:,. .,.
                   .     ...;cl:.          ':ldxxdocccclol;.      ..:;.',.
                   .   .;llc;',c;.       .,:,''';::;'.  ..          .;:;'
                      .:xdoxko,',.      .,:. .;llc:ldl.              .;c.
                      .lxdoxkd:''.     .;:.  .cxl'';od;.          .. .,,
                      .:clool;.',.     .:'   .:dxolccl;.         .::;,:'
                       .;::,.. .,.     .;.   .,:;:;,,;'         .,;,:ol.
                         ..    ',.     .;.    .',,,,,.          .,:llc;.
                              .,'      .,.                      .;lxxc'
                             .,;.      .;.                      .;lxxc.
            ..              .;;.       .:'                      .;cc,.
           ...';'          .;;.        .;:.                      ,:'
          .;c:;.       .. .,;.       ....,;.                     .'.
         .,lc,.      .':,..,:,''....;c:;'':'..              ..   .'.
         .;:;.      .,:'   .::,,;;;;;..',;,..,,.            .,.  .'.
        .'',,.     .,;.                      .;,            .'.  ...
        .'',,.    .,;.                        ';.           .,.  .'.
        .'...     .;.                         .,,.          .,'   ..
        .'.      .;,.                          .::.         .,'   .
        .'.     .,;.                            ,c'         .,'  .'.
        .'.     .:'                             .,'          .. .,'
         ''.    ,;.    .....................    .;'            .:,
         .,.   .,;.   ..'''''''''''''''''','.  .,;.           .::.
          .,.   ,;.                           .,;.           .;,.
          .,,.  .:,.                         .;;.          .''.
           .,'   .'.                         ...          .,.
            .''                                          .,.
             .,'.                                       .'.
              .'.                                      .*/

#include <fstream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <map>

#define int long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define all(v) v.begin(), v.end()
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("unroll-loops")

using namespace std;

template<typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
    _out << _p.first << ' ' << _p.second;
    return _out;
}

template<typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
    _in >> _p.first >> _p.second;
    return _in;
}

template<typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
    if (_v.empty()) { return _out; }
    _out << _v.front();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}

template<typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}

const int MAXN = 3e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

pr<int, int> format(pr<int, int> a) {
    int d = __gcd(a.fs, a.sc);
    a.fs /= d;
    a.sc /= d;
    if (a.fs < 0) {
        a.fs *= -1;
        a.sc *= -1;
    }
    return a;
}

class DVanyaITreugolniki {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        vc<pr<int, int>> as(n);
        in >> as;
        int ans = n * (n - 1) * (n - 2);
        for (int i = 0; i < n; i++) {
            map<pr<int, int>, int> k;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    pr<int, int> kes = {as[j].fs - as[i].fs, as[j].sc - as[i].sc};
                    k[format(kes)]++;
                }
            }
            for (auto v : k) {
                ans -= v.sc * (v.sc - 1);
            }
        }
        out << ans / 6;
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	DVanyaITreugolniki solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}