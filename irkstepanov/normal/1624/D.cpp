#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int sigma = 26;

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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(sigma);
        for (int i = 0; i < sz(s); ++i) {
            ++a[s[i] - 'a'];
        }
        int ans = 1;
        for (int l = 2; ; ++l) {
            vector<int> b = a;
            if (l & 1) {
                int done = 0;
                for (int i = 0; i < sigma; ++i) {
                    if (done < k && b[i] % 2) {
                        --b[i];
                        ++done;
                    }
                }
                for (int i = 0; i < sigma; ++i) {
                    while (done < k && b[i]) {
                        --b[i];
                        ++done;
                    }
                }
                if (done < k) {
                    break;
                }
            }
            int total = 0;
            for (int i = 0; i < sigma; ++i) {
                total += b[i] / 2;
            }
            if (total >= k * (l / 2)) {
                ans = l;
            } else {
                break;
            }
        }
        cout << ans << "\n";
    }

}