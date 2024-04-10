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
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;
        vector<int> cnt(sigma, 0);
        for (int i = 0; i < sz(s); ++i) {
            ++cnt[s[i] - 'a'];
        }
        vector<char> vct;
        for (int i = 0; i < sigma; ++i) {
            if (cnt[i] == 1) {
                cout << char(i + 'a');
            } else if (cnt[i] == 2) {
                vct.pb(char(i + 'a'));
            }
        }
        for (char c : vct) {
            cout << c << c;
        }
        cout << "\n";
    }

}