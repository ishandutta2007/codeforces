#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<char> ans(sz(s));
    int curr = sz(s);
    if (curr % 2 == 0) {
        --curr;
    }
    int ptr = 0;

    while (curr >= 1) {
        ans[curr - 1] = s[ptr++];
        curr -= 2;
    }
    curr = 2;
    while (curr <= sz(s)) {
        ans[curr - 1] = s[ptr++];
        curr += 2;
    }

    for (int i = 0; i < sz(s); ++i) {
        cout << ans[i];
    }
    cout << "\n";

}