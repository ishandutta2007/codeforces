#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

bool grid[1000][1000];

int stairSizeLeft(int x, int y);

int stairSizeUp(int x, int y) {
    if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return 0;
    if (!grid[x][y]) return 0;
    return 1 + stairSizeLeft(x - 1, y);
}

int stairSizeLeft(int x, int y) {
    int out = 0;
    while (true) {
        if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return out;
        if (!grid[x][y]) return out;
        out++;
        y--;
        if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return out;
        if (!grid[x][y]) return out;
        out++;
        x--;
    }
}

int stairSizeDown(int x, int y);

int stairSizeRight(int x, int y) {
    int out = 0;
    while (true) {
        if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return out;
        if (!grid[x][y]) return out;
        out++;
        y++;
        if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return out;
        if (!grid[x][y]) return out;
        out++;
        x++;
    }
}

int stairSizeDown(int x, int y) {
    if (x < 0 || y < 0 || x >= 1000 || y >= 1000) return 0;
    if (!grid[x][y]) return 0;
    return 1 + stairSizeRight(x + 1, y);
}

int numcases(int sizeOfStair) {
    if (sizeOfStair == 0) return 0;
    return (sizeOfStair * (sizeOfStair - 1)) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) grid[i][j] = true;

    ll out = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int toright = stairSizeRight(i, j);
            out += toright - 1;
            int todown = stairSizeDown(i, j);
            out += todown - 1;
        }
    }
    ll numones = n * m;

    //cout << out << ' ' << numones << endl;

    //cout << "start " << out + numones << endl;

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        if (grid[x][y]) {
            // We turn something off.
            // Crawl up...
            /*int toup = stairSizeUp(x, y) - 1;

            // This is connected with going to the right;
            int toright = stairSizeRight(x, y) - 1;

            int newval = toup + toright + 1;

            int oldstairnum = numcases(toright) + numcases(toup);
            int newstairnum = numcases(newval);

            out -= newstairnum;
            out += oldstairnum;

            int toleft = stairSizeLeft(x, y) - 1;

            int todown = stairSizeDown(x, y) - 1;
            newval = toleft + todown + 1;

            oldstairnum = numcases(toleft) + numcases(todown);
            newstairnum = numcases(newval);

            out -= newstairnum;
            out += oldstairnum;*/

            int toup = stairSizeUp(x, y) - 1;
            int toright = stairSizeRight(x, y) - 1;
            int toleft = stairSizeLeft(x, y) - 1;
            int todown = stairSizeDown(x, y) - 1;

            out -= toup;
            out -= toright;
            out -= toleft;
            out -= todown;
            
            out -= toup*toright;
            out -= todown*toleft;

            numones--;
            grid[x][y] = false;
        } else {
            // We turn something on.
            grid[x][y] = true;
            numones++;

            // Crawl up...
            int toup = stairSizeUp(x, y) - 1;

            // This is connected with going to the right;
            int toright = stairSizeRight(x, y) - 1;

            int newval = toup + toright + 1;

            int oldstairnum = numcases(toright) + numcases(toup);
            int newstairnum = numcases(newval);

            out += newstairnum;
            out -= oldstairnum;

            int toleft = stairSizeLeft(x, y) - 1;

            int todown = stairSizeDown(x, y) - 1;
            newval = toleft + todown + 1;

            oldstairnum = numcases(toleft) + numcases(todown);
            newstairnum = numcases(newval);

            out += newstairnum;
            out -= oldstairnum;

        }

        cout << out+numones << endl;
    }
}