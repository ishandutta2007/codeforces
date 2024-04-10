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

map<string, vector<string> > g;
set<string> nr;
set<string> dir;
map<string, int> sd;
map<string, int> sf;

void dfs(string s)
{
    if (sd.count(s)) return;
    int& r1 = sd[s];
    int& r2 = sf[s];
    sort(all(g[s]));
    g[s].erase(unique(all(g[s])), g[s].end());
    for (int i = 0; i < sz(g[s]); ++i) {
        dfs(g[s][i]);
        int rr1 = 0, rr2 = 0;
        if (dir.count(g[s][i]))
            rr1 = 1;
        else
            rr2 = 1;
        r1 += rr1 + sd[g[s][i]];
        r2 += rr2 + sf[g[s][i]];
    }
    //cerr << s << ": " << r1 << " " << r2 << "\n";
}

int main()
{
    string s;
    while (cin >> s)
    {
        vector<string> v;
        string cur;
        for (int i = 0; i < sz(s); ++i) {
            if (s[i] == '\\')
                v.pb(cur);
            cur += s[i];
        }
        if (sz(cur)) v.pb(cur);
        for (int i = 0; i < sz(v) - 1; ++i) {
            g[v[i]].pb(v[i + 1]);
            nr.insert(v[i + 1]);
            dir.insert(v[i]);
        }
    }
    int r1 = 0, r2 = 0;
    for (map<string, vector<string> >::iterator it = g.begin(); it != g.end(); ++it) {
        if (!nr.count(it->first)) continue;
        if (!dir.count(it->first)) continue;
        dfs(it->first);
        r1 = max(r1, sd[it->first]);
        r2 = max(r2, sf[it->first]);
    }
    cout << r1 << " " << r2 << "\n";
    return 0;
}