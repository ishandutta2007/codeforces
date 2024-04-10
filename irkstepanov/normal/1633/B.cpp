#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int f(const string& s) {
    int cnt[2] = {0, 0};
    for (int i = 0; i < sz(s); ++i) {
        ++cnt[s[i] - '0'];
    }
    if (cnt[0] != cnt[1]) {
        return min(cnt[0], cnt[1]);
    } else {
        return 0;
    }
}

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
        if (sz(s) == 1) {
            cout << "0\n";
            continue;
        }
        string t = s.substr(0, sz(s) - 1);
        string u = s.substr(1, sz(s) - 1);
        cout << max({f(s), f(t), f(u)}) << "\n";
    }

}