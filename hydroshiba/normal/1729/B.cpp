#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    string cur = "", ans = "";
    reverse(s.begin(), s.end());

    for(char c : s){
        cur += c;
        if(c == '0') continue;

        if(c != '0'){
            if(cur[0] == '0'){
                reverse(cur.begin(), cur.end());
                int t = stoi(cur) / 10;
                if(t < 10){
                    reverse(cur.begin(), cur.end());
                    continue;
                }

                ans += char(t + 'a' - 1);
            }
            else{
                reverse(cur.begin(), cur.end());
                int t = stoi(cur);
                ans += char(t + 'a' - 1);
            }

            cur.clear();
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}