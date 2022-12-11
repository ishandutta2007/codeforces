#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    ios::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n, k;
    cin >> n >> k;
    --k;
    vector<vector<int> > m(n, vector<int>(n));
    int curr = n * n;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= k; --j) {
            m[i][j] = curr--;
            if (j == k) {
                ans += m[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = k - 1; j >= 0; --j) {
            m[i][j] = curr--;
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

}