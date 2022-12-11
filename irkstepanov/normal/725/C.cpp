#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");

    string s;
    cin >> s;

    for (int i = 0; i < sz(s) - 1; ++i) {
        if (s[i] == s[i + 1]) {
            cout << "Impossible\n";
            return 0;
        }
    }

    int pos0 = -1, pos1 = -1;
    for (int i = 0; i < sz(s); ++i) {
        for (int j = i + 1; j < sz(s); ++j) {
            if (s[i] == s[j]) {
                pos0 = i;
                pos1 = j;
            }
        }
    }

    int len = pos1 - pos0 - 1;

    vector<vector<char> > ans(2, vector<char>(13, -1));

    if (len & 1) {
        ans[0][len / 2] = s[pos0];
        int curr = pos0 + 1;
        for (int i = len / 2; i >= 0; --i) {
            ans[1][i] = s[curr++];
        }
        for (int i = 0; i < len / 2; ++i) {
            ans[0][i] = s[curr++];
        }
    } else {
        ans[0][len / 2] = s[pos0];
        int curr = pos0 + 1;
        for (int i = len / 2 - 1; i >= 0; --i) {
            ans[1][i] = s[curr++];
        }
        for (int i = 0; i < len / 2; ++i) {
            ans[0][i] = s[curr++];
        }
    }

    int curr = pos1 + 1;
    if (curr == sz(s)) {
        curr = 0;
    }

    int x = 0, y = len / 2 + 1;
    if (y >= 13) {
        x = 1;
        y = len / 2;
    }

    while (curr != pos0) {
        ans[x][y] = s[curr++];
        if (curr == sz(s)) {
            curr = 0;
        }
        if (y + 1 == 13 && ans[x ^ 1][y] == -1) {
            x ^= 1;
        } else {
            if (y + 1 == 13) {
                --y;
            } else {
                if (ans[x][y + 1] == -1) {
                    ++y;
                } else {
                    --y;
                }
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 13; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

}