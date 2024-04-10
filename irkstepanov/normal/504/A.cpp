#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long double ld;

const int N = (1 << 16) + 10;

pii m[N];

struct data
{
    int n, d, x;
};

bool operator < (data a, data b)
{
    if (a.d < b.d) return true;
    if (a.d > b.d) return false;
    return a.n < b.n;
}

int main()
{

    set <data> s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d, x;
        cin >> d >> x;
        m[i] = mp(d, x);
        data tmp = {i, d, x};
        s.insert(tmp);
    }

    vector <pii> edges;

    while (!s.empty())
    {
        set <data> :: iterator it = s.begin();
        data tmp = *it;
        s.erase(tmp);
        if (!tmp.d) continue;
        int v = tmp.n, u = tmp.x;
        edges.pb(mp(v, u));
        data old = {u, m[u].first, m[u].second};
        s.erase(old);
        --m[u].first;
        m[u].second ^= tmp.n;
        data old1 = {u, m[u].first, m[u].second};
        s.insert(old1);
    }

    cout << sz(edges) << "\n";
    for (int i = 0; i < sz(edges); i++)
        cout << edges[i].first << " " << edges[i].second << "\n";

}