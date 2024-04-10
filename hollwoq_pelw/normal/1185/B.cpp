#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;
    vector<pair<char, int>> cs, ct;
    cin >> s >> t;
    int c;
    char k;
    s += '!';
    c = 1;
    k = s[0];
    for (int i = 1; i < s.length(); i++){
        if (s[i] == k) c++;
        else{
            cs.push_back({k, c});
            k = s[i];
            c = 1;
        }
    }
    t += '!';
    c = 1;
    k = t[0];
    for (int i = 1; i < t.length(); i++){
        if (t[i] == k) c++;
        else{
            ct.push_back({k, c});
            k = t[i];
            c = 1;
        }
    }
    if (ct.size() != cs.size()){
        cout << "NO\n";
        return ;
    }
    for (int i = 0; i < cs.size(); i++){
        //cout << cs[i].first << ' ' << cs[i].second << ' ';
        //cout << ct[i].first << ' ' << ct[i].second << '\n';
        if (cs[i].first == ct[i].first && cs[i].second <= ct[i].second){
            continue;
        }else{
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    return ;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}