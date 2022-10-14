#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 7005;

int n;
llint a[MAXN], b[MAXN];
map <llint, int> mp;
bool bio[MAXN];

void uzmi (llint mask) {
    for (int i=0; i<n; i++) {
        if ((a[i] & mask) == a[i]) bio[i] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    for (auto par : mp) {
        llint val = par.first, br = par.second;
        if (br >= 2) uzmi(val);
    }
    llint sol = 0;
    for (int i=0; i<n; i++) {
        if (bio[i]) sol += b[i];
    }
    cout << sol;
    return 0;
}