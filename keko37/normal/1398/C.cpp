#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;
map <int, int> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> n >> s;
        int sum = 0;
        mp[0]++;
        for (auto c : s) {
            sum += c - '0' - 1;
            mp[sum]++;
        }
        llint sol = 0;
        for (auto par : mp) {
            llint br = par.second;
            sol += br * (br - 1) / 2;
        }
        cout << sol << '\n';
    }
    return 0;
}