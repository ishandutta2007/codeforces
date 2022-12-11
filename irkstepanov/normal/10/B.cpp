#include <bits/stdc++.h>

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

const int inf = 1e9;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n, k;
    cin >> n >> k;
    int x0 = (k + 1) / 2, y0 = (k + 1) / 2;

    vector<vector<char> > used(k + 1, vector<char>(k + 1, false));

    while (n--) {
        int m;
        cin >> m;
        int d = inf;
        int xans, yans;
        for (int x = 1; x <= k; ++x) {
            for (int l = 1; l + m - 1 <= k; ++l) {
                int r = 0;
                bool ok = true;
                for (int i = l; i <= l + m - 1; ++i) {
                    if (used[x][i]) {
                        ok = false;
                        break;
                    }
                    r += abs(x - x0) + abs(i - y0);
                }
                if (ok && r < d) {
                    d = r;
                    xans = x;
                    yans = l;
                }
            }
        }
        if (d == inf) {
            cout << "-1\n";
            continue;
        }
        for (int i = yans; i <= yans + m - 1; ++i) {
            used[xans][i] = true;
        }
        cout << xans << " " << yans << " " << yans + m - 1 << "\n";
    }

}