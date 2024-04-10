#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a, s;
    cin >> a >> s;

    string ans;

    while(s.size()){
        char x = (a.empty() ? '0' : *a.rbegin());
        char u = (s.empty() ? '0' : *s.rbegin());
        char v = (s.size() < 2 ? '0' : s[s.size() - 2]);

        if(x <= u){
            char digit = int(u) - int(x) + int('0');
            ans += char(u - x + 48);
            if(!s.empty()) s.erase(--s.end());
        }
        else{
            if(v != '1'){
                cout << "-1\n";
                return;
            }

            char digit = 10 - int(x) + int(u) + int('0');
            ans += digit;

            if(!s.empty()) s.erase(--s.end());
            if(!s.empty()) s.erase(--s.end());
        }

        if(!a.empty()) a.erase(--a.end());
    }

    if(!a.empty()){
        cout << "-1\n";
        return;
    }

    reverse(ans.begin(), ans.end());
    while(ans[0] == '0') ans.erase(ans.begin());
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}