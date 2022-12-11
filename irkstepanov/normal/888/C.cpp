#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string s;
    cin >> s;

    int lf = 0, rg = sz(s);
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        bool ok = false;
        for (char c = 'a'; c <= 'z'; ++c) {
            int cnt = 0;
            for (int i = 0; i < md; ++i) {
                if (s[i] == c) {
                    ++cnt;
                }
            }
            if (cnt == 0) {
                continue;
            }
            bool co = true;
            for (int i = md; i < sz(s); ++i) {
                if (s[i] == c) {
                    ++cnt;
                }
                if (s[i - md] == c) {
                    --cnt;
                }
                if (cnt == 0) {
                    co = false;
                    break;
                }
            }
            if (co) {
                ok = true;
                break;
            }
        }
        if (ok) {
            rg = md;
        } else {
            lf = md;
        }
    }

    cout << rg << "\n";

}