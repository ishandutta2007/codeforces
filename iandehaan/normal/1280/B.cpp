#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        int out = 1e9;
        char board[r][c];
        bool seen = false;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch;
                cin >> board[i][j];
                ch = board[i][j];
                if (ch == 'P') seen = true;
                if (ch == 'A') {
                    out = min(out, 4);
                    if (i == 0 || j == 0 || i == r-1 || j == c-1) {
                        out = min(out, 3);
                    }

                    if ((i == 0 || i == r-1) && (j == 0 || j == c-1)) {
                        out = min(out, 2);
                    }
                }
            }
        }
        if (!seen) out = 0;

        for (int i = 0; i < r; i++) {
            bool good = true;
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'P') {
                    good = false;
                    break;
                }
            }
            if (good && (i == 0 || i == r-1)) out = min(out, 1);
            if (good) out = min(out, 2);
        }

        for (int j = 0; j < c; j++) {
            bool good = true;
            for (int i = 0; i < r; i++) {
                if (board[i][j] == 'P') {
                    good = false;
                    break;
                }
            }
            if (good && (j == 0 || j == c-1)) out = min(out, 1);
            if (good) out = min(out, 2);
        }


        if (out == 1e9) cout << "MORTAL" << endl;
        else cout << out << endl;
    }
}