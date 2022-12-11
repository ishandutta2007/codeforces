#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    int ans = 0, curr = 0;
    int prev;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i == 0) {
            prev = a;
            curr = 1;
            ans = 1;
            continue;
        }
        if (a > prev) {
            prev = a;
            ++curr;
            ans = max(curr, ans);
        } else {
            prev = a;
            curr = 1;
            ans = max(ans, curr);
        }
    }

    cout << ans << "\n";

}