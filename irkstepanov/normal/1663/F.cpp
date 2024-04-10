#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<string> v = {"buffy", "the", "vampire", "slayer"};
    string s;
    cin >> s;

    int p = -1;
    for (int i = 0; i < sz(v); ++i) {
        if (sz(v[i]) == sz(s)) {
            p = i;
        }
    }
    if (p == -1) {
        cout << "none\n";
        return 0;
    }
    for (int i = 0; i < sz(s); ++i) {
        int x = ((s[i] - 'a') + (v[p][i] - 'a')) % 26;
        cout << char(x + 'a');
    }
    cout << "\n";

}