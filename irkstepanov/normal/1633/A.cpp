#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        if (n % 7 == 0) {
            cout << n << "\n";
            continue;
        }
        bool done = false;
        for (int x = n; ; ++x) {
            if (x / 10 != n / 10) {
                break;
            }
            if (x % 7 == 0) {
                cout << x << "\n";
                done = true;
                break;
            }
        }
        if (done) {
            continue;
        }
        for (int x = n; ; --x) {
            if (x / 10 != n / 10) {
                break;
            }
            if (x % 7 == 0) {
                cout << x << "\n";
                break;
            }
        }
    }

}