#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '.') {
            cout << 0;
            continue;
        }
        if (s[i + 1] == '.') {
            cout << 1;
        } else {
            cout << 2;
        }
        ++i;
    }
    cout << "\n";

}