#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

vector<vector<char> > ans;
int n;
vector<vector<char> > t;

void f(int x, int y, int s, int k)
{
    if (k == 0) {
        return;
    }
    int step = s / n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (t[i][j] == '*') {
                for (int ii = x + i * step; ii < x + (i + 1) * step; ++ii) {
                    for (int jj = y + j * step; jj < y + (j + 1) * step; ++jj) {
                        ans[ii][jj] = '*';
                    }
                }
            } else {
                f(x + i * step, y + j * step, step, k - 1);
            }
        }
    }
}

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> n >> k;
    int s = 1;

    for (int i = 0; i < k; ++i) {
        s *= n;
    }

    ans.resize(s);
    for (int i = 0; i < s; ++i) {
        ans[i].assign(s, '.');
    }
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        t[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> t[i][j];
        }
    }

    f(0, 0, s, k);

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

}