#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 15;

int t, n;
string in[MAXN];
map <string, int> mp;

string pro (string s) {
    for (int i = 0; i < 4; i++) {
        for (char c = '0'; c <= '9'; c++) {
            string t = s;
            t[i] = c;
            if (mp.find(t) == mp.end()) return t;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            mp[in[i]]++;
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            string s = in[i];
            if (mp[s] > 1) {
                sol++;
                string t = pro(s);
                mp[s]--; mp[t]++;
                in[i] = t;
            }
        }
        cout << sol << endl;
        for (int i = 0; i < n; i++) cout << in[i] << endl;
    }
    return 0;
}