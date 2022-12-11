#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        p[a[i]] = i;
    }

    vector<int> dp(n);
    dp[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i) {
        if (p[i + 1] < p[i]) {
            dp[i] = 1;
        } else {
            dp[i] = 1 + dp[i + 1];
        }
    }

    int ans = n - 1;
    for (int pref = 0; pref < n; ++pref) {
        int relax = pref;
        relax += (n - pref - dp[pref]);
        ans = min(ans, relax);
    }
    cout << ans << "\n";

}