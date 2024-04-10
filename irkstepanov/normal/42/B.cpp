#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int tp[8][8];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool beat(int x, int y) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tp[i][j] == 1) {
                if (i == x) {
                    int cnt = 0;
                    for (int k = 0; k < 8; ++k) {
                        if (k > min(j, y) && k < max(j, y)) {
                            cnt += tp[i][k];
                        }
                    }
                    if (cnt == 0) {
                        return true;
                    }
                } else if (j == y) {
                    int cnt = 0;
                    for (int k = 0; k < 8; ++k) {
                        if (k > min(i, x) && k < max(i, x)) {
                            cnt += tp[k][j];
                        }
                    }
                    if (cnt == 0) {
                        return true;
                    }
                }
            }
            if (tp[i][j] == 2) {
                for (int k = 0; k < 8; ++k) {
                    if (i + dx[k] == x && j + dy[k] == y) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char a, b;
    for (int i = 0; i < 2; ++i) {
        cin >> a >> b;
        tp[a - 'a'][b - '1'] = 1;
    }

    cin >> a >> b;
    tp[a - 'a'][b - '1'] = 2;
    cin >> a >> b;

    int x = a - 'a', y = b - '1';
    tp[x][y] = 3;

    if (!beat(x, y)) {
        cout << "OTHER\n";
        return 0;
    }

    for (int k = 0; k < 8; ++k) {
        int xx = x + dx[k], yy = y + dy[k];
        if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) {
            continue;
        }
        if (tp[xx][yy] == 0) {
            swap(tp[x][y], tp[xx][yy]);
            if (!beat(xx, yy)) {
                cout << "OTHER\n";
                return 0;
            }
            swap(tp[x][y], tp[xx][yy]);
        } else {
            assert(tp[xx][yy] == 1);
            tp[xx][yy] = 3;
            tp[x][y] = 0;
            if (!beat(xx, yy)) {
                cout << "OTHER\n";
                return 0;
            }
            tp[xx][yy] = 1;
            tp[x][y] = 3;
        }
    }

    cout << "CHECKMATE\n";

}