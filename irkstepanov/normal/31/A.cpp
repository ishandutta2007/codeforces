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
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (i == k || j == k) {
                    continue;
                }
                if (a[i] == a[j] + a[k]) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";

}