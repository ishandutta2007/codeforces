#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int pos = 0;

    while (n--) {
        int x;
        string s;
        cin >> x >> s;
        if (s[0] == 'W' || s[0] == 'E') {
            if (pos == 0 || pos == 20000) {
                cout << "NO\n";
                return 0;
            }
            continue;
        }
        if (s[0] == 'S') {
            if (pos + x > 20000) {
                cout << "NO\n";
                return 0;
            }
            pos += x;
        }
        if (s[0] == 'N') {
            if (pos - x < 0) {
                cout << "NO\n";
                return 0;
            }
            pos -= x;
        }
    }

    cout << (pos == 0 ? "YES\n" : "NO\n");

}