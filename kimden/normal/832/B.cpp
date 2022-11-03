#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    string good;
    cin >> good;
    map<char, char> mp;
    for(int i = 0; i < 26; ++i){
        mp['a' + i] = 0;
    }
    for(int i = 0; i < good.length(); ++i){
        mp[good[i]] = 1;
    }
    string tem;
    cin >> tem;
    int star = -1;
    for(int i = 0; i < tem.length(); ++i){
        if(tem[i] == '*'){
            star = i;
            break;
        }
    }
    int n;
    cin >> n;
    string s;
    bool b;
    if(star == -1){
        for(int i = 0; i < n; ++i){
            b = true;
            cin >> s;
            if(s.length() != tem.length()){
                cout << "NO" << endl;
                continue;
            }
            for(int j = 0; j < s.length(); ++j){
                if((tem[j] == '?' && mp[s[j]] == 0) || (tem[j] != '?' && s[j] != tem[j])){
                    b = false;
                    cout << "NO" << endl;
                    break;
                }
            }
            if(b){
                cout << "YES" << endl;
            }
        }
    }else{
        for(int i = 0; i < n; ++i){
            b = true;
            cin >> s;
            if(s.length() + 1 < tem.length()){
                cout << "NO" << endl;
                continue;
            }
            for(int j = 0; j < star; ++j){
                if((tem[j] == '?' && mp[s[j]] == 0) || (tem[j] != '?' && s[j] != tem[j])){
                    b = false;
                    cout << "NO" << endl;
                    break;
                }
            }
            if(!b){
                continue;
            }
            for(int j = 0; j < (int)tem.size() - 1 - star; ++j){
                if((tem[tem.length() - 1 - j] == '?' && mp[s[s.length() - 1 - j]] == 0) || (tem[tem.length() - 1 - j] != '?' && s[s.length() - 1 - j] != tem[tem.length() - 1 - j])){
                    b = false;
                    cout << "NO" << endl;
                    break;
                }
            }
            if(b){
                for(int j = star; j < star + (int)s.length() - (int)tem.length() + 1; ++j){
                    if(mp[s[j]] == 1){
                        b = false;
                        cout << "NO" << endl;
                        break;
                    }
                }
                if(b) {
                    cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}