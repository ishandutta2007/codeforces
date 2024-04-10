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

int main()
{
    map<char, vi> M;
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < sz(s); ++i)
        M[s[i]].pb(i);
    vector<pair<int, vi> > v;
    for (map<char, vi>::iterator it = M.begin(); it != M.end(); ++it) {
        v.pb(mp(sz(it->second), it->second));
    }
    sort(all(v));
    reverse(all(v));
    int m = 0;
    int ind = 0;
    vi u(sz(s), 0);
    int n = sz(s);
    int cnt = 0;
    while (m + k < n) {
        ++cnt;
        m += v[ind].first;
        for (int i = 0; i < sz(v[ind].second); ++i)
            u[v[ind].second[i]] = 1;
        ++ind;
    }
    cout << cnt << "\n";
    for (int i = 0; i < sz(s); ++i)
        if (u[i]) printf("%c", s[i]);
    printf("\n");
    return 0;
}