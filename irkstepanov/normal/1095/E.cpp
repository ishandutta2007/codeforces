#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> b(n);
    if (s[0] == '(') {
        b[0] = 1;
    } else {
        b[0] = -1;
    }

    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1];
        if (s[i] == '(') {
            ++b[i];
        } else {
            --b[i];
        }
    }

    vector<int> minn(n);
    minn[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minn[i] = min(minn[i + 1], b[i]);
    }

    int ans = 0;
    int sum = b[n - 1];
    int val = 0;

    for (int i = 0; i < n; ++i) {
        bool good = true;
        if (s[i] == '(' && sum - 2 != 0) {
            good = false;
        }
        if (s[i] == ')' && sum + 2 != 0) {
            good = false;
        }
        if (val < 0) {
            good = false;
        }
        if (s[i] == '(' && minn[i] < 2) {
            good = false;
        }
        if (s[i] == ')' && minn[i] < -2) {
            good = false;
        }
        if (good) {
            ++ans;
        }
        val = min(val, b[i]);
    }

    cout << ans << "\n";

}