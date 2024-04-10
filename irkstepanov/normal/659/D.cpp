#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

struct pt
{
    int x, y;
};

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;
    ++n;
    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (p[i].x == p[i + 1].x) {
            if (p[i].y < p[i + 1].y) {
                if (p[i + 2].x < p[i].x) {
                    ++ans;
                }
            } else {
                if (p[i + 2].x > p[i].x) {
                    ++ans;
                }
            }
        } else {
            if (p[i].x < p[i + 1].x) {
                if (p[i + 2].y > p[i].y) {
                    ++ans;
                }
            } else {
                if (p[i + 2].y < p[i].y) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << "\n";

}