#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("triangles.out");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char f[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> f[i][j];
        }
    }

    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            if (f[x][y] == '.') {
                f[x][y] = 'x';
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (f[i][j] == 'x' && f[i][j + 1] == 'x' && f[i][j + 2] == 'x') {
                            cout << "YES\n";
                            return 0;
                        }
                    }
                }
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        if (f[i][j] == 'x' && f[i + 1][j] == 'x' && f[i + 2][j] == 'x') {
                            cout << "YES\n";
                            return 0;
                        }
                    }
                }
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (f[i][j] == 'x' && f[i + 1][j + 1] == 'x' && f[i + 2][j + 2] == 'x') {
                            cout << "YES\n";
                            return 0;
                        }
                    }
                }
                for (int i = 0; i < 2; ++i) {
                    for (int j = 2; j < 4; ++j) {
                        if (f[i][j] == 'x' && f[i + 1][j - 1] == 'x' && f[i + 2][j - 2] == 'x') {
                            cout << "YES\n";
                            return 0;
                        }
                    }
                }
                f[x][y] = '.';
            }
        }
    }

    cout << "NO\n";

}