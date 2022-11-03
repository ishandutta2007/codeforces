#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    string s;
    int mx = 0;
    int cur;
    int k;
    cin >> k;
    while(cin >> s){
        cur = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ++cur;
            }
        }
        mx = max(mx, cur);
    }
    cout << mx << endl;

    return 0;
}