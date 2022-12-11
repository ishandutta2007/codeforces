#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int y, b, r;
    cin >> y >> b >> r;

    int ans = 0;
    for (int i = 1; i <= y; ++i) {
        if (i + 1 <= b && i + 2 <= r) {
            ans = i + i + 1 + i + 2;
        }
    }

    cout << ans << "\n";

}