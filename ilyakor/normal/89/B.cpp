#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

struct wid {
    int t;
    int x, y;
    int bord;
    int sp;
    vector<string> v;
    wid() : t(0), x(0), y(0), bord(0), sp(0) {}
};

typedef pair<int64, int64> II;

map<string, wid> M;
map<string, II> d;

II eval(string s) {
    if (d.count(s)) return d[s];
    II& res = d[s];
    wid& w = M[s];
    if (w.t == 0)
        return res = II(w.x, w.y);
    if (w.t == 1) {
        int64 x = 0, y = 0;
        for (int i = 0; i < sz(w.v); ++i) {
            II cur = eval(w.v[i]);
            x = max(x, cur.first);
            y += cur.second;
            if (i) y += w.sp;
        }
        if (sz(w.v)) {
            x += 2 * w.bord;
            y += 2 * w.bord;
        }
        res = II(x, y);
    } else {
        int64 x = 0, y = 0;
        for (int i = 0; i < sz(w.v); ++i) {
            II cur = eval(w.v[i]);
            y = max(y, cur.second);
            x += cur.first;
            if (i) x += w.sp;
        }
        if (sz(w.v)) {
            x += 2 * w.bord;
            y += 2 * w.bord;
        }
        res = II(x, y);
    }
    return res;
}

int main()
{
    int n;
    char buf[100500];
    gets(buf);
    sscanf(buf, "%d", &n);
    for (int it = 0; it < n; ++it) {
        gets(buf);
        for (int j = 0; buf[j]; ++j)
            if (buf[j] == ',' || buf[j] == '.' || buf[j] == '(' || buf[j] == ')') buf[j] = ' ';
        stringstream ss(buf);
        string s;
        ss >> s;
        if (s == "Widget") {
            ss >> s;
            int x, y;
            ss >> x >> y;
            wid w;
            w.x = x;
            w.y = y;
            w.t = 0;
            M[s] = w;
        } else if (s == "VBox") {
            ss >> s;
            wid w;
            w.t = 1;
            M[s] = w;
        } else if (s == "HBox") {
            ss >> s;
            wid w;
            w.t = 2;
            M[s] = w;
        } else {
            string nm = s;
            ss >> s;
            if (s == "pack") {
                string S;
                ss >> S;
                M[nm].v.pb(S);
            } else if (s == "set_border") {
                int x;
                ss >> x;
                M[nm].bord = x;
            } else {
                int x;
                ss >> x;
                M[nm].sp = x;
            }
        }
    }
    vector<pair<string, II> > v;
    for (map<string, wid>::iterator it = M.begin(); it != M.end(); ++it) {
        v.pb(mp(it->first, eval(it->first)));
    }
    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
        cout << v[i].first << " " << v[i].second.first<< " "  << v[i].second.second << "\n";
    return 0;
}