#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    map<string, string> mp;
    string s, t;
    for(int i = 0; i < q; ++i){
        cin >> s >> t;
        mp[s] = t;
    }
    int ans = 0;
    int mx = 1;
    for(int i = 0; i < n; ++i){
        mx *= 6;
    }
    for(int i = 0; i < mx; ++i){
        s = "";
        int cur = i;
        for(int j = 0; j < n; ++j){
            s += (char)(cur % 6 + 'a');
            cur /= 6;
        }
        while(s.length() > 1){
            if(mp.count(s.substr(0, 2)) == 0){
                break;
            }
            s = mp[s.substr(0, 2)] + s.substr(2, s.length() - 2);
        }
        if(s == "a"){
            ++ans;
        }
    }
    cout << ans << endl;
}