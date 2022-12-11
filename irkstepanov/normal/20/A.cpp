#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    bool ok = true;

    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != '/') {
            ok = false;
        }
        if (s[i] == '/') {
            continue;
        }
        if (i && s[i] != '/' && s[i - 1] == '/') {
            cout << s[i - 1];
        }
        cout << s[i];
    }
    if (ok == true) {
        cout << "/";
    }
    cout << "\n";

}