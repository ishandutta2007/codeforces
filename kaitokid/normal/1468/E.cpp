#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<ll> v(4);
        for (int i = 0; i < 4; ++i) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        cout << v[0] * v[2] << "\n";
    }

    return 0;
}