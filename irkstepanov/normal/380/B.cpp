#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <queue>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;
const int inf = 100500;

bool pow2(int x)
{
    int cnt = 0;
    while (x) {
        if (x & 1) {
            ++cnt;
        }
        x >>= 1;
    }
    return cnt == 1;
}

struct query
{
    int l, r, x;
};

const int nmax = 1e7;

vector<vector<query> > q;
vector<int> v;

void solve(int level, int l, int r)
{
    for (query& tmp : q[level]) {
        if ((tmp.l >= l && tmp.l <= r) || (tmp.r >= l && tmp.r <= r) || (l >= tmp.l && l <= tmp.r) || (r >= tmp.l && r <= tmp.r)) {
            v.pb(tmp.x);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    cin >> n;

    int leftist[nmax], rightist[nmax];
    leftist[1] = 1;
    rightist[1] = 2;

    for (int i = 2; i < nmax; ++i) {
        leftist[i] = rightist[i - 1] + 1;
        if (pow2(i)) {
            rightist[i] = leftist[i] + 1;
        } else {
            rightist[i] = leftist[i];
        }
    }

    q.resize(n + 1);
    int m;
    cin >> m;

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int level, l, r, x;
            cin >> level >> l >> r >> x;
            query tmp = {l, r, x};
            q[level].pb(tmp);
        } else {
            int level, pos;
            cin >> level >> pos;
            v.clear();
            int l = pos, r = pos;
            for (int i = level; i <= n; ++i) {
                solve(i, l, r);
                if (i != n) {
                    l = leftist[l];
                    r = rightist[r];
                }
            }
            sort(all(v));
            v.resize(unique(all(v)) - v.begin());
            cout << sz(v) << "\n";
        }
    }

}