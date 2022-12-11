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

    int tt;
    cin >> tt;

    while (tt--) {
        int x;
        cin >> x;
        for (int n = 3; ; ++n) {
            if ((x * n) % 180 == 0) {
                int k = (x * n) / 180;
                if (k <= n - 2) {
                    cout << n << "\n";
                    break;
                }
                
            }
        }
    }

}