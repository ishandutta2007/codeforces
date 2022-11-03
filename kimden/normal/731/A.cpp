#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int rot(char a, char b){
    int aa = a - 'a';
    int bb = b - 'a';
    return min((aa - bb + 26) % 26, (bb - aa + 26) % 26);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll ans = 0;
    char x = 'a';
    char y;
    for(int i = 0; i < s.length(); i++){
        y = s[i];
        ans += rot(x, y);
        x = y;
    }
    cout << ans;
    return 0;
}