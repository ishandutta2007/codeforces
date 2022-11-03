#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    s += 'A';
    int cur = -1;
    int ans = -1e9;
    string t = "AEOUIY";
    for(int i = 0; i < s.length(); ++i){
        if(t.find(s[i]) != string::npos){
            ans = max(ans, i - cur);
            cur = i;
        }
    }
    cout << ans << endl;
}