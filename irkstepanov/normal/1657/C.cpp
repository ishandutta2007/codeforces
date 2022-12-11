#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int nmax = 200;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        int f = 0;
        while (true) {
            if (f >= n - 1) {
                break;
            }
            if (!(s[f] == ')' && s[f + 1] == '(')) {
                f += 2;
                cnt += 1;
                continue;
            }
            int nx = f + 2;
            while (nx < n && s[nx] != ')') {
                ++nx;
            }
            if (nx == n) {
                break;
            }
            cnt += 1;
            f = nx + 1;
        }
        cout << cnt << " " << n - f << "\n";
    }

}