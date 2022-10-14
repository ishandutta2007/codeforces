#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint n, sol;
string s;
llint cnt[26][26], p[26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[j][s[i] - 'a'] += p[j];
        }
        p[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        sol = max(sol, (llint) p[i]);
        for (int j = 0; j < 26; j++) {
            sol = max(sol, cnt[i][j]);
        }
    }
    cout << sol;
    return 0;
}