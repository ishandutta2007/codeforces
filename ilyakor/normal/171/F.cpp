#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

void doit() {
    string s, t;
    while (cin >> t) s += " " + t;
    map<int, int> M;
    for (int i = 0; i < sz(s); ++i) if (isalpha(s[i])) M[s[i]]++;
    vector<pair<int, char > > v;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        v.pb(mp(it->second, (char)(it->first)));
    }
    sort(all(v));
    reverse(all(v));
    map<char, char> d;
    
    string ps = "eintrsomauphfdbglyckwvjxqz";
    for (int i =0 ; i < sz(v); ++i) {

        d[v[i].second] = ps[i];
        cerr << "map " << v[i].second << " to " << ps[i] << "\n";
    }
    for (int i = 0; i < sz(s); ++i) if (d.count(s[i])) s[i] = d[s[i]];
    cout << s << "\n";

}

bool isprime(int64 x) {
    for (int64 i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

bool good(int64 res) {
    if (!isprime(res)) return false;
    int64 x = 0;
    int64 y = res;
    while (res) x = x * 10 + res % 10, res /= 10;
    if (y == x) return false;
    return isprime(x);
}

int main()
{
    //doit();
    int64 a;
    cin >> a;
    /*int64 res = 1;
    for (int64 i = 2; i <= a; ++i) {
        res += 12LL * (i - 1);
    }*/
    int64 res = 11;
    for (int it = 0; it < a; ++it) {
        ++res;
        while (!good(res)) ++res;
    }
    cout << res << "\n";
    return 0;
}