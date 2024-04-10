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

vi vb;

vector<pair<int, string> > r;

int vind;
int IT = 1;

bool check(int pl) {
    if (pl >= vind) return true;
    int score = r[vind].first + vb[0];
    for (int i = pl; i < vind; ++i) {
        if (r[i].first + vb[sz(vb) - i + pl - 1]  > score)
            return false;

        if (r[i].first + vb[sz(vb) - i + pl - 1]  == score) {
            if (IT == 1 && r[i].second < r[vind].second)
                return false;
            if (IT == 2 && r[i].second > r[vind].second)
                return false;
        }
    }
    return true;
}

bool cmp(pair<int, string> p, pair<int, string> q) {
    if (p.first != q.first) return p.first > q.first;
    return p.second < q.second;
}

int main()
{
    int n;
    cin >> n;
    char buf[100];
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%s%d", buf, &x);
        r.pb(mp(x, string(buf)));
    }
    int m;
    cin >> m;
    vb.resize(m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &vb[i]);
    while (sz(vb) < n)
        vb.pb(0);
    sort(all(vb));
    reverse(all(vb));
    string vas;
    cin >> vas;
    
    sort(all(r), cmp);
    for (int i = 0; i < sz(r); ++i)
        if (r[i].second == vas)
            vind = i;

    int up, down;

    IT = 1;
    up = n - 1, down = 0;
    while (up - down > 1) {
        int t = (up + down) / 2;
        if (check(t))
            up = t;
        else
            down = t;
    }
    int r1 = check(down) ? down : up;

    for (int i = 0; i < n; ++i)
        r[i].first = -r[i].first, vb[i] = -vb[i];
    reverse(all(r));
    reverse(all(vb));
    vind = n - vind - 1;

    IT = 2;
    up = n - 1, down = 0;
    while (up - down > 1) {
        int t = (up + down) / 2;
        if (check(t))
            up = t;
        else
            down = t;
    }
    int r2 = check(down) ? down : up;
    r2 = n - r2 - 1;

    printf("%d %d\n", r1 + 1, r2 + 1);
    return 0;
}