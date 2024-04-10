#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int n;
string s, sol;

void rjesi (int ll, int rr) {
    if (rr - ll + 1 <= 3) {
        sol += s[ll];
        return;
    }
    if (s[ll] == s[rr]) {
        rjesi(ll + 1, rr - 1);
        sol += s[ll];
        return;
    }
    if (s[ll+1] == s[rr]) {
        rjesi(ll + 2, rr - 1);
        sol += s[rr];
        return;
    }
    if (s[ll] == s[rr-1]) {
        rjesi(ll + 1, rr - 2);
        sol += s[ll];
        return;
    }
    rjesi(ll + 2, rr - 2);
    sol += s[ll+1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    rjesi(0, n-1);
    reverse(sol.begin(), sol.end());
    cout << sol;
    sol = sol.substr(0, sol.size() - 1);
    reverse(sol.begin(), sol.end());
    cout << sol;
    return 0;
}