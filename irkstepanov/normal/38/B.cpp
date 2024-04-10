#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<char> > m(8, vector<char>(8, true));

void horse(const string& s)
{
    int x = s[0] - 'a';
    int y = s[1] - '1';
    m[x][y] = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int a = abs(x - i), b = abs(y - j);
            if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
                m[i][j] = false;
            }
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s;
    cin >> s;

    int x = s[0] - 'a';
    int y = s[1] - '1';
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == x || j == y) {
                m[i][j] = false;
            }
        }
    }
    horse(s);
    cin >> s;
    horse(s);

    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (m[i][j]) {
                ++ans;
            }
        }
    }
    cout << ans << "\n";

}