#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 3050;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1; a <= n; ++a) {
        int x = a;
        int cnt = 0;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                ++cnt;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x != 1) {
            ++cnt;
        }
        if (cnt == 2) {
            ++ans;
        }
    }
    cout << ans << "\n";

}