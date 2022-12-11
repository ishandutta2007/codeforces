#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = -1; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j <= i; ++j) {
            if (a[j] == 0) {
                ++sum;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == 1) {
                ++sum;
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << "\n";

}