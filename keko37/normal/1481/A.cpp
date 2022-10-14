#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, px, py;
string s;
map <char, int> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> px >> py >> s;
        for (auto c : s) mp[c]++;
        if (-mp['L'] <= px && px <= mp['R'] && -mp['D'] <= py && py <= mp['U']) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}