#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    char grid[9][9];

    for (int i = 0; i < 9; i++) {
        string str = "";
        while (str.size() < 11) {
            getline(cin, str);
        }

        int j = 0;
        for (char c : str) {
            if (c != ' ')
                grid[i][j++] = c;
        }
    }

    int X, Y;
    cin >> X >> Y;
    X--, Y--;

    int sx = X%3*3, sy = Y%3*3;
    bool open = false;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            if (grid[sx + dx][sy + dy] == '.')
                open = true;
        }
    }

    if (open) {
        for (int dx = 0; dx < 3; dx++) {
            for (int dy = 0; dy < 3; dy++) {
                if (grid[sx + dx][sy + dy] == '.')
                    grid[sx + dx][sy + dy] = '!';
            }
        }
    } else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.')
                    grid[i][j] = '!';
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j];
            if (j % 3 == 2) cout << " ";
        }
        cout << endl;
        if (i % 3 == 2) cout << endl;
    }

    return 0;
}