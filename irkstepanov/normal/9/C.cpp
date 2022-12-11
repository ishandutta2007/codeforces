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

const int inf = 1e9;

bool bit(int mask, int pos)
{
    return mask & (1 << pos);
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("division.out");

    int n;
    cin >> n;

    int ans = 0;
    if (n == inf) {
        ++ans;
        --n;
    }

    for (int mask = 1; mask < (1 << 9); ++mask) {
        int t = 0;
        int deg = 1;
        for (int i = 0; i < 9; ++i) {
            if (bit(mask, i)) {
                t += deg;
            }
            deg *= 10;
        }
        if (t <= n) {
            ++ans;
        }
    }

    cout << ans << "\n";

}