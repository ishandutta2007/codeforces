#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int nmax = 100500;
const int rmax = 50;

int main()
{

    //ifstream cin("input.txt");

    int a, b;
    ll n;

    cin >> a >> b >> n;

    vector<vector<char> > dp(nmax, vector<char>(rmax, '?'));

    for (int x = 2; x < nmax; ++x) {
        ll val = x;
        int pos = 1;
        while (val < n) {
            val *= ll(x);
            ++pos;
        }
        for (int i = pos; i < rmax; ++i) {
            dp[x][i] = '+';
        }
    }

    if (nmax - 1 < n) {
        ll d = n - (nmax - 1);
        if (d & 1) {
            dp[nmax - 1][1] = '-';
        } else {
            dp[nmax - 1][1] = '+';
        }
    }

    for (int i = nmax - 1; i >= 2; --i) {
        for (int j = rmax - 1; j >= 1; --j) {
            if (dp[i][j] != '?') {
                continue;
            }
            if (dp[i + 1][j] == '-' || dp[i][j + 1] == '-') {
                dp[i][j] = '+';
            } else {
                dp[i][j] = '-';
            }
        }
    }

    dp[1][rmax - 1] = '=';
    for (int j = rmax - 2; j >= 1; --j) {
        if (dp[1][j + 1] == '-' || dp[2][j] == '-') {
            dp[1][j] = '+';
        } else if (dp[1][j + 1] == '=') {
            dp[1][j] = '=';
        } else {
            dp[1][j] = '-';
        }
    }

    if (dp[a][b] == '+') {
        cout << "Masha\n";
    } else if (dp[a][b] == '-') {
        cout << "Stas\n";
    } else {
        cout << "Missing\n";
    }

}