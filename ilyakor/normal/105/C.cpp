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

bool cmp(pair<string, int> p, pair<string, int> q) {
    return p.second > q.second;
}

int main()
{
    int n;
    cin >> n;
    map<string, vi> w;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        string name, s;
        cin >> name >> s;
        int t;
        if (s == "weapon") t = 0;
        else if (s == "armor") t = 1;
        else if (s == "orb") t = 2;

        int a, d, r, si;
        cin >> a >> d >> r >> si;
        vi v;
        v.pb(t);
        v.pb(a);
        v.pb(d);
        v.pb(r);
        v.pb(si);
        w[name] = v;
        sum += si;
    }

    int k;
    cin >> k;
    vector<pair<string, int> > gems[3];
    vector<string> homes[3];
    for (int i = 0; i < k; ++i) {
        string name, type, home;
        int bonus;
        cin >> name >> type >> bonus >> home;
        int t;
        if (type == "gladiator") t = 0;
        else if (type == "sentry") t = 1;
        else if (type == "physician") t = 2;
        homes[t].pb(home);
        gems[t].pb(mp(name, bonus));
    }

    if (k < sum) {
        vector<string> r(3);
        vi val(3, -1);
        for (int i = 0; i < 3; ++i)
            sort(all(gems[i]), cmp);
        for (map<string, vi>::iterator it = w.begin(); it != w.end(); ++it) {
            int t = w[it->first][0];
            int x = w[it->first][1 + t];
            int S = w[it->first][4];
            for (int i = 0; i < sz(gems[t]) && i < S; ++i)
                x += gems[t][i].second;
            if (x > val[t])
                val[t] = x, r[t] = it->first;
        }
        queue<ii> q;
        for (int t = 0; t < 3; ++t) {
            string s = r[t];
            int S = w[s][4];
            for (int i = 0; i < sz(gems[t]); ++i) {
                if (i < S)
                    homes[t][i] = s;
                else {
                    homes[t][i] = '.';
                    q.push(ii(t, i));
                }
            }           
        }
        for (int t = 0; t < 3; ++t) {
            string s = r[t];
            int S = w[s][4];
            for (int i = sz(gems[t]); i < S; ++i) {
                if (q.empty()) break;
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                homes[a][b] = s;
            }
        }
    }

    vector<string> r(3);
    vi val(3, -1);
    for (map<string, vi>::iterator it = w.begin(); it != w.end(); ++it) {
        int t = w[it->first][0];
        int x = w[it->first][1 + t];
        for (int i = 0; i < sz(gems[t]); ++i)
            if (homes[t][i] == it->first)
                x += gems[t][i].second;
        if (x > val[t])
            val[t] = x, r[t] = it->first;
    }
    for (int t = 0; t < 3; ++t) {
        cout << r[t] << " ";
        vector<string> v;
        for (int tt = 0; tt < 3; ++tt)
            for (int i = 0; i < sz(gems[tt]); ++i)
                if (homes[tt][i] == r[t])
                    v.pb(gems[tt][i].first);
        cout << sz(v);
        sort(all(v));
        for (int i = 0; i < sz(v); ++i)
            printf(" %s", v[i].c_str());
        printf("\n");
    }
    return 0;
}