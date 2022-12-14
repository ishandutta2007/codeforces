/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

/*                         _________________
                      ____/:::::::::::::::::\_____
                   __/::::::::::::::::::::::::::::\___
                 _/:::::::::::::::::::::::::::::::::::\__
               _/::::::::::::::::::::::::::::::::::::::::\_
              /::::::::::::::::::::::::::::::::::::::::::::\
             |::::::::::::::::::::::::::::::::::::::::::::::\
            /::::::::::::::::::::::::::::::::::::::::::::::::\
           |:::/.:::::::;:::::::::::::::::::::::::::::::::::::|
          /:::/.:::::::/..:::::::::::::::::::::::::::::::::::::\
         |:::|.::::::;/.::::::::::::::::::::::::::::::::::::::::|
         |::/.::::::/..:::::::;;'.::::::::::::::::::::::::::::::|
         |:|.::::/./.::::::;;/..:::::::::::::::::::::::::::::::::|
         `:|.:::|.|.:::::;/..;;;;;;-'.:;;;-':::::::::::::::::::::|
          \|.:::|.|.:::;/.;;/  -..::'''...:::::::::::::::::::::::|
           \;;::|.|.::/.;/--__      |::::::::::::::::::::::::::::|
              \;;\\::/|/ =-__ --_  /::::::::::::::::::::::::::::::
                  \\/    /|  -._  |.::::::::::::::::::::::::::::::
                 _.'    ///   /-  ||::::::::::::::::::::::::::::::
             _.-'      //'        ||::::::::::::::::::::::::::::::
            |          -          `|::::::::::::::::::::::::::::::
             \                      \:::::::::::::::::::::::::::::
              |                      \:::::::::::PART:10::::::::::
             /                      __/:::::::::::::::::::::::::::
             \                   __/::;::;;::::::       ::::::::::
             |`                 /;;;;/::|  \::::  :___:  :::::::::
             \                 |'_,::::/ \ |:::: .|  |`. :::::::::
             /                _/::::::/  / /:::: | \.' | ::. .::::
            |                /.::;;:-'_)/_/::::: `._| .' ::.D.::::
 ----.__    |               |.::|   \___/:::::::         ::.i.::::
 :::::::`----\_____          \:::\.-'::::::::::: ___:___ ::.z.::::
 ;;;;;:::::::::::::`------     \:::::::::::::::: ___|___ ::.z.::::
      `-------:::::::\         /::::::::::::::::  __|    ::.y.::::
 ___.--------'::::::::\       |::::::::::::::::: |  |-.  ::.n.::::
 :::::;;;:--:::::::::::|      /:::::::::::::::::  --'  ' ::.e.::::
 ----'  _,-:.:::::::::::\    |.:::::::::::::::::         ::.s.::::
     __/.::::::::::::::::|   |.:::::::::::::::::  :   :  ::.s.::::
  __/.:::;;::::::::;/.:::|   |.:::::::::::::::::  |    : ::. .::::
 /.::::;/ /.:::::;/ |.::::|   \_.:::::::::::::::  | .  | :::::::::
 :::::/  /.:::::/  /.:::::|     \__.::::::::::::  `.'  ' :::::::::
 ::::|  |.:::::/  /.:::::.|        \,::::::::::::       ::::::::::
 ::::|  |.::::|   |.:::::/|       __/:::::::::::::::::::::::::::::
 \.:::\  \.:::|   |.::::||| __.--::::::::::::::::::::::GST::::::::
  \.:::\_ \.:::\   \.:::'/.:::::::::::::::::::::::::::::55min:::::
   \.::::\ \.:::\   \.::::::::::::::::::::::::::::::::::::::::::*/

#include <fstream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

#define int long long
#define ld long double
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

const int MAXN = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

ld dist(pr<int, int> a, pr<int, int> b) {
    return sqrt((ld) ((a.fs - b.fs) * (a.fs - b.fs) + (a.sc - b.sc) * (a.sc - b.sc)));
}

class AMusorNaPererabotku {
public:
    void solve(std::istream &in, std::ostream &out) {
        pr<int, int> a, b, o;
        in >> a >> b >> o;
        int n;
        in >> n;
        vc<pr<int, int>> d(n);
        in >> d;
        vc<pr<ld, int>> aa;
        vc<pr<ld, int>> bb;
        ld ans = 0;
        for (int i = 0; i < n; i++) {
            aa.pb({-dist(d[i], a) + dist(d[i], o), i});
            bb.pb({-dist(d[i], b) + dist(d[i], o), i});
            ans += dist(d[i], o) * 2;
        }
        sort(all(aa));
        sort(all(bb));
        reverse(all(aa));
        reverse(all(bb));
        if (aa[0].sc != bb[0].sc) {
            ans -= max(aa[0].fs + bb[0].fs, max(aa[0].fs, bb[0].fs));
        } else {
            if (n == 1) {
                ans -= max(aa[0].fs, bb[0].fs);
            } else {
                ans -= max(max(aa[0].fs, bb[0].fs),
                           max(aa[0].fs + bb[1].fs, bb[0].fs + aa[1].fs));
            }
        }
        out << fixed << setprecision(19) << ans << '\n';
    }
};


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    AMusorNaPererabotku solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}