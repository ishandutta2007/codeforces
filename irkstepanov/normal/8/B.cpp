#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int nmax = 200;

int main()
{

    vector<vector<int> > m(nmax * 2, vector<int>(nmax * 2, 0));

    int x = nmax, y = nmax;
    m[x][y] = 1;

    string s;
    cin >> s;

    forn(i, sz(s)) {
        int xOld = x, yOld = y;
        if (s[i] == 'L') {
            --x;
        }
        if (s[i] == 'R') {
            ++x;
        }
        if (s[i] == 'U') {
            ++y;
        }
        if (s[i] == 'D') {
            --y;
        }
        if (m[x][y]) {
            cout << "BUG\n";
            return 0;
        }
        if (x + 1 != xOld && m[x + 1][y]) {
            cout << "BUG\n";
            return 0;
        }
        if (x - 1 != xOld && m[x - 1][y]) {
            cout << "BUG\n";
            return 0;
        }
        if (y + 1 != yOld && m[x][y + 1]) {
            cout << "BUG\n";
            return 0;
        }
        if (y - 1 != yOld && m[x][y - 1]) {
            cout << "BUG\n";
            return 0;
        }
        m[x][y] = 1;
    }

    cout << "OK\n";

}