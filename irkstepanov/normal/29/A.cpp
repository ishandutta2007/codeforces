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
    vector<int> x(n), d(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> d[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

}