#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int del[MAXN];
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        int sol = 0;
        for (int i = 0; i < n; i++) {
            del[i] = 0;
            if ((i >= 1 && s[i-1] == s[i] && del[i-1] == 0) || (i >= 2 && s[i-2] == s[i] && del[i-2] == 0)) {
                del[i]++;
                sol++;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}