#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '<') {
            ++ans;
        } else {
            break;
        }
    }
    for (int i = sz(s) - 1; i >= 0; --i) {
        if (s[i] == '>') {
            ++ans;
        } else {
            break;
        }
    }

    cout << ans << "\n";

}