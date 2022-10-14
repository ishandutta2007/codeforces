#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

typedef long long llint;

int n, flg, win;
int a[MAXN];
map <int, int> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (mp[0] >= 2 || mp[0] == n) {
        cout << "cslnb";
        return 0;
    }
    int cnt = 0, ind = -1;
    for (auto par : mp) {
        int br = par.first, fq = par.second;
        if (fq >= 2) {
            cnt++;
            ind = br;
        }
    }
    if (cnt >= 2) {
        cout << "cslnb";
        return 0;
    }
    if (ind != -1) {
        if (mp[ind] > 2 || mp[ind-1] > 0) {
            cout << "cslnb";
            return 0;
        }
        mp[ind]--;
        mp[ind-1]++;
        flg = 1;
    }
    llint sum = 0;
    for (auto par : mp) {
        llint br = par.first, fq = par.second;
        sum += br * fq;
    }
    for (int i=0; i<n; i++) {
        sum -= i;
    }
    win = sum % 2;
    if (flg) win = !win;
    if (win == 0) cout << "cslnb"; else cout << "sjfnb";
    return 0;
}