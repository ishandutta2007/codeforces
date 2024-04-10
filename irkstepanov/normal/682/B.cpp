#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    int n;
    cin >> n;
    vector<int> a(n);

    fori {
        cin >> a[i];
    }
    sort(all(a));

    int ans = 1;
    fori {
        if (a[i] >= ans) {
            ++ans;
        }
    }

    cout << ans << "\n";

}