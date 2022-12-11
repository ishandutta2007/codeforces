#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int nmax = 55;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    int m[nmax][nmax];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        vector<int> cnt(n + 1);
        for (int j = 0; j < n; ++j) {
            ++cnt[m[i][j]];
            if (cnt[m[i][j]] > 1) {
                p[i] = m[i][j];
            }
        }
    }

    int val = n - 1;
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            p[i] = val++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }

}