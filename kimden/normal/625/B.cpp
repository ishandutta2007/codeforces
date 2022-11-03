#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    string s, t;
    int ans = 0;
    cin >> s >> t;
    for(int i = 0; i < (int)s.length() - (int)t.length() + 1; i++){
        if(s.substr(i, t.length()) == t){
            s[i + t.length() - 1] = '#';
            ans++;
        }
    }
    cout << ans;
    return 0;
}