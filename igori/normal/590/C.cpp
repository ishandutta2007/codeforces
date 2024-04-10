#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define ll long long
#define pb push_back
#define pii pair<long long, long long>
#include <map>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef  double dd;

const int N = 1000;
const int inf = 1e9;
int lst[N][N];
int dp[3][N][N];
vector < pair < int, int > > dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] ==  '#')
                continue;
            if (s[j] == '.')
                lst[i][j] = 1;
            else
                lst[i][j] = (s[j] - '0') + 1;
        }
    }

    for (int t = 0; t < 3; t++) {
        deque < pair < int, int > > q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                dp[t][i][j] = inf;
                if (lst[i][j] == t + 2) {
                    q.push_back({i, j});
                    dp[t][i][j] = 0;
                }
            }
            while (q.size()) {
                pair < int, int > fr = q.front();
                q.pop_front();
                int x = fr.first, y = fr.second;
                for (pair < int, int > k : dir) {
                    int a = k.first + x, b = k.second + y;

                    if (ok(a, b) && lst[a][b] && dp[t][a][b] == inf) {
                        if (lst[a][b] > 1) {
                            dp[t][a][b] = dp[t][x][y];
                            q.push_front({a, b});
                        } else {
                            dp[t][a][b] = dp[t][x][y] + 1;
                            q.push_back({a, b});
                        }
                        //dp[t][a][b] = dp[t][x][y] + !(lst[a][b] > 1);

                    }
                }
            }
    }
    


    ll ans = inf - 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll sum = 0;
            int fl = 1;
            for (int t = 0; t < 3; t++) {
                sum += dp[t][i][j];
                if (lst[i][j] > 1)
                    fl = 0;
            }
            //cerr << sum << endl;
            ans = min(ans, sum - 2 * fl);
        }
    }
    //cerr << ans << endl << endl << endl;
    if (ans == inf - 5)
        cout << -1;
    else
        cout << ans;
    return 0;
}