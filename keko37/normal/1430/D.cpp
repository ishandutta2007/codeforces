#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        v.clear();
        int br = 0;
        for (int i = 0; i < n; i++) {
            br++;
            if (i == n-1 || s[i] != s[i + 1]) {
                v.push_back(br);
                br = 0;
            }
        }
        int sol = 0, curr = 0;
        for (int i = 0; i < v.size(); i++) {
            if (curr < i) curr = i;
            while (curr < v.size() && v[curr] == 1) curr++;
            if (curr < v.size()) {
                sol++;
                v[curr]--;
            } else {
                sol += (v.size() - i + 1) / 2;
                break;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}