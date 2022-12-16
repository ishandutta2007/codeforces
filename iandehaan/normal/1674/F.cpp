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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    char grid[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];

    int numstar = 0;
    rep(i, 0, n) rep(j, 0, m) if (grid[i][j] == '*') numstar++;

    int currans = 0;
    rep(i, 0, n) rep(j, 0, m) {
        int ind = n*j + i + 1;
        //cout << i << ' ' << j << ' ' << ind << endl;
        if (numstar < ind && grid[i][j] == '*') currans++;
    }

    //cout << "starting " << currans << endl;

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (grid[x][y] == '*') {
            // gain one?
            int ind = n*y + x + 1;
            if (numstar < ind) currans--; 
            
            numstar--;
            int losey = numstar / n;
            int losex = numstar - n*losey;
            if ((losex != x || losey != y) && grid[losex][losey] == '*') currans++;


            grid[x][y] = '.';

        } else {
            int ind = n*y + x + 1;
            if (numstar+1 < ind) currans++; 
            
            
            int losey = numstar / n;
            int losex = numstar - n*losey;
            if ((losex != x || losey != y) && grid[losex][losey] == '*') currans--;

            numstar++;


            grid[x][y] = '*';
        }

        cout << currans << endl;
    }
}