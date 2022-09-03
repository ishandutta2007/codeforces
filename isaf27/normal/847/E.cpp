#include <bits/stdc++.h>

using namespace std;

//#define int int64_t

const int INF = 1e18;

const int MAXN = 2 * 1e5 + 1;

vector <int> p, g;
vector <int> f;

int get_max_nxt(int x, int pos, int time) {
    if (pos - x > time)
        return -1;
    int p1 = (time - (pos - x)) / 2 + pos;

    int p2 = x + (time - (pos - x));

    return max(p1, p2);
}

bool check(int x) {
    f = g;
    int last = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        //cout << p[i] << " : " << endl;
        if (last >= (int)f.size())
            return true;
        int x0 = p[i];
        if (x0 >= f[last]) {
            int x1 = get_max_nxt(f[last], x0, x);

            if (x1 == -1)
                return false;

            while (last < (int)f.size() && f[last] <= max(x1, x0)) {
                //cout << "   " << f[last] << endl;
                last++;
            }
        } else {
            int x1 = x0 + x;
            while (last < (int)f.size() && f[last] <= x1) {
                //cout << "   " << f[last] << endl;
                last++;
            }
        }
    }

    return last >= (int)f.size();
}

int32_t main()
{
    #define fname "test"
    /*freopen(fname".in", "r", stdin);
    /*freopen(fname".out", "w", stdout); /**/

    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P')
            p.push_back(i);
        else if (s[i] == '*')
            g.push_back(i);
    }

    int l = -1, r = 1e6;

    while (r - l > 1) {
        int m = (l + r + 1) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }

    cout << r << endl;

    return 0;
}