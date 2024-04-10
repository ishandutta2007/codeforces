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

#define inf 1e9
#define MAXN 200'010

ll memo[MAXN][3];
char board[MAXN][2];

ll dp(int ind, int piecepos) {
    // piecepos 0, 1, or 2
    // 2 signifies empty
    if (ind == -1) {
        if (piecepos == 2) return 0;
        else return inf;
    }

    if (memo[ind][piecepos] != -1) return memo[ind][piecepos];


    ll out = inf;
    for (int prevpiece = 0; prevpiece <= 2; prevpiece++) {
        ll med = dp(ind-1, prevpiece);
        // have to move the piece over
        if (prevpiece != 2) med++;
        if (piecepos == 0) {
            if (prevpiece == 1 || board[ind][1] == '*') med++; // move up
            if (board[ind][0] == '.' && board[ind][1] == '.') {
                if (prevpiece == 2) {
                    med = inf; // can't fill
                }
            }
        } else if (piecepos == 1) {
            if (prevpiece == 0 || board[ind][0] == '*') med++;
            if (board[ind][0] == '.' && board[ind][1] == '.') {
                if (prevpiece == 2) {
                    med = inf; // can't fill
                }
            }
        } else {
            if (prevpiece != 2) med = inf; // can't put it anywhere
            if (board[ind][0] == '*' || board[ind][1] == '*') med = inf;
        }
        out = min(out, med);
    }
    
    return memo[ind][piecepos] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            memo[i][0] = -1;
            memo[i][1] = -1;
            memo[i][2] = -1;
        }
        int latestpos = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[j][i];
                if (board[j][i] == '*') latestpos = max(latestpos, j);
            }
        }
        cout << min(dp(latestpos, 0), dp(latestpos, 1)) << '\n';
    }
}