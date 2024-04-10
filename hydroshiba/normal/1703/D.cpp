#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> vec(n);
    unordered_set<string> ss;

    for(string &i : vec) cin >> i, ss.insert(i);

    string ans;

    for(string i : vec){
        bool flag = 0;
        for(int j = 1; j < i.size(); ++j){
            string a = i.substr(0, j);
            string b = i.substr(0 + j, i.size() - j);

            if(ss.find(a) != ss.end() && ss.find(b) != ss.end()){
                flag = 1;
                break;
            }
        }

        if(flag) ans += "1";
        else ans += "0";
    }

    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}