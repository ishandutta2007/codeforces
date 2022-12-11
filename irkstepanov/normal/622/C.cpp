#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const int amax = (int)(1e6 + 10);

int main()
{

    //ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n, q;
    scanf("%d%d", &n, &q);
    //cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        //cin >> a[i];
    }

    vector<int> pos[amax];

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            pos[a[i]].pb(i);
        }
    }

    while (q--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        //cin >> l >> r >> x;
        --l, --r;
        if (a[l] != x) {
            printf("%d\n", l + 1);
            //cout << l + 1 << "\n";
            continue;
        }
        if (a[r] != x) {
            printf("%d\n", r + 1);
            //cout << r + 1 << "\n";
            continue;
        }
        int t = lower_bound(all(pos[x]), l) - pos[x].begin();
        if (t == sz(pos[x])) {
            printf("-1\n");
            //cout << "-1\n";
            continue;
        }
        int p = pos[x][t];
        if (p < r) {
            printf("%d\n", p + 2);
            //cout << p + 2 << "\n";
        } else {
            printf("-1\n");
            //cout << "-1\n";
        }
    }

}