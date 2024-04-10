#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int k = 0;
        for(int i = 0; i < s.size(); i++) k += (s.at(i) == 'B');
        if(2*k == s.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}