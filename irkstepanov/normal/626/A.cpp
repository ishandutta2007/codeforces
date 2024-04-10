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
typedef pair<int, int> edge;

string s;
int ans = 0;

void f(int l, int r)
{
    int x = 0, y = 0;
    for (int i = l; i <= r; ++i) {
        if (s[i] == 'U') {
            ++x;
        }
        if (s[i] == 'D') {
            --x;
        }
        if (s[i] == 'L') {
            ++y;
        }
        if (s[i] == 'R') {
            --y;
        }
    }
    if (x == 0 && y == 0) {
        ++ans;
    }
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    cin >> n;
    cin >> s;
    for (int l = 0; l < sz(s); ++l) {
        for (int r = l; r < sz(s); ++r) {
            f(l, r);
        }
    }

    cout << ans << "\n";

}