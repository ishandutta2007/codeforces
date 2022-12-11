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
        string s;
        cin >> s;
        int lst = -1;
        for (int i = 0; i < sz(s) - 1; ++i) {
            int x = s[i] - '0';
            int y = s[i + 1] - '0';
            if (x + y >= 10) {
                lst = i;
            }
        }
        if (lst != -1) {
            for (int i = 0; i < lst; ++i) {
                cout << s[i];
            }
            int x = s[lst] - '0';
            int y = s[lst + 1] - '0';
            cout << x + y;
            for (int i = lst + 2; i < sz(s); ++i) {
                cout << s[i];
            }
        } else {
            int x = s[0] - '0';
            int y = s[1] - '0';
            cout << x + y;
            for (int i = 2; i < sz(s); ++i) {
                cout << s[i];
            }
        }
        cout << "\n";
    }

}