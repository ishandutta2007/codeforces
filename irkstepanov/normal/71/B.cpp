#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, k, t;
    cin >> n >> k >> t;

    int sum = (n * k * t) / 100;
    for (int i = 0; i < n; ++i) {
        if (sum >= k) {
            cout << k << " ";
            sum -= k;
        } else {
            cout << sum << " ";
            sum = 0;
        }
    }
    cout << "\n";

}