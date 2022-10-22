#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long   ll;
typedef long double ld;

#define all(x)  (x).begin(), (x).end()
#define sz(x)   (x).size()
#define pb      push_back
#define mp      make_pair
#define fr      first
#define sc      second

string s, t;
int n;

void input() {
    cin >> n;
    cin >> s >> t;
}

void solve() {
    vector<int> cnts(26, 0);
    for(char c : s) {
        cnts[c - 'a']++;
    }
    for(char c : t) {
        cnts[c - 'a']++;
    }
    for(int elem : cnts) {
        if (elem & 1) {
            puts("No");
            return;
        }
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        bool fndt = 0;
        for(int j = i + 1; j < n; j++) {
            if (t[i] == t[j]) {
                ans.emplace_back(i, j);
                swap(s[i], t[j]);
                fndt = true;
                break;
            }
        }
        if (fndt) continue;
        for(int j = i + 1; j < n; j++) {
            if (s[j] == t[i]) {
                ans.emplace_back(j, i + 1);
                swap(s[j], t[i + 1]);
                ans.emplace_back(i, i + 1);
                swap(s[i], t[i + 1]);
                break;
            }
        }
    }
    puts("Yes");
    cout << sz(ans) << endl;
    for(auto& pr : ans) {
        cout << pr.fr + 1 << " " << pr.sc + 1 << endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        input();
        solve();
    }
    return 0;
}