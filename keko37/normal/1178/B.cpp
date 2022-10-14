#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

llint n, sol;
string s;
llint pref[MAXN], suf[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i=1; i<n; i++) {
        pref[i] = pref[i-1];
        if (s[i] == 'v' && s[i-1] == 'v') pref[i]++;
    }
    for (int i=n-2; i>=0; i--) {
        suf[i] = suf[i+1];
        if (s[i] == 'v' && s[i+1] == 'v') suf[i]++;
    }
    for (int i=1; i<n-1; i++) {
        if (s[i] == 'o') sol += pref[i-1] * suf[i+1];
    }
    cout << sol;
    return 0;
}