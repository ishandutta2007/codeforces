#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    double ans = 0;

    string str;
    cin >> str;

    int ct[26];

    for (int c = 0; c < 26; c++) {
        vi locs;
        for (int i = 0; i < str.size(); i++)
            if (str[i] == ('a' + c))
                locs.push_back(i);

        int best = 0;
        for (int s = 0; s < str.size(); s++) {
            fill(ct, ct + 26, 0);
            for (int i : locs) {
                int cn = str[(i + s)%str.size()] - 'a';
                ct[cn]++;
            }

            int uniq = 0;
            for (int v : ct) {
                if (v == 1)
                    uniq++;
            }
            best = max(best, uniq);
        }
        ans += best * 1.0 / str.size();
    }

    cout << ans << endl;
    return 0;
}