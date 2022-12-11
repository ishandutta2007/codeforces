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

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n, p1, p2, p3;
    int t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    int curr = 0;
    int state = 0;
    int spent = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (i == 0) {
            curr = l;
        }
        while (curr < l) {
            if (state == 0) {
                ans += p1;
            } else if (state == 1) {
                ans += p2;
            } else {
                ans += p3;
            }
            ++spent;
            if (state == 0 && spent == t1) {
                state = 1;
                spent = 0;
            } else if (state == 1 && spent == t2) {
                state = 2;
                spent = 0;
            }
            ++curr;
        }
        ans += (r - l) * p1;
        curr = r;
        state = 0;
        spent = 0;
    }

    cout << ans << "\n";

}