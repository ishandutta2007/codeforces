#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("triangles.out");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    vector<int> p(n + 1, -1);
    p[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 1; --j) {
            if (sum[i] - sum[j - 1] != 0 && p[j - 1] != -1) {
                p[i] = j;
                break;
            }
        }
    }

    if (p[n] == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<pii> ans;
    int curr = n;
    while (curr != 0) {
        ans.pb({p[curr], curr});
        curr = p[curr] - 1;
    }

    cout << "YES\n";
    reverse(all(ans));
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

}