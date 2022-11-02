#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

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
    int n, m;
    cin >> n >> m;
    vi v;
    int fx, fy;
    cin >> fx >> fy;
    int lx = fx, ly = fy;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb(abs(x - lx) + abs(y - ly));
        lx = x, ly = y;
    }
    v.pb(abs(fx - lx) + abs(fy - ly));
    multiset<int> _S;
    map<int, set<int> > M;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        _S.insert(x);
        M[x].insert(i);
    }
    for (int it = 0; it < 2; it++)
    {
        multiset<int> S = _S;
        bool ok = true;
        for (int i = 0; i < sz(v); i += 2)
        {
            int x = v[i] + v[i + 1];
            if (!S.count(x))
            {
                ok = false;
                break;
            }
            S.erase(S.find(x));
        }
        if (ok)
        {
            printf("YES\n");
            vi res;
            for (int i = 0; i < sz(v); i += 2)
            {
                int x = v[i] + v[i + 1];
                int y = *M[x].begin();
                M[x].erase(y);
                res.pb(-1);
                res.pb(y + 1);
            }
            if (it)
                rotate(res.begin(), res.end() - 1, res.end());
            for (int i = 0; i < sz(res); i++)
                cout << res[i] << " ";
            cout << "\n";
            return 0;
        }
        rotate(v.begin(), v.begin() + 1, v.end());
    }
    printf("NO\n");
    return 0;
}