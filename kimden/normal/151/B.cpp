#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<pair<int, string>, vector<int>> mp;
    vector<int> mx(3, 0);
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        string t;
        getline(cin, t);
        for(int j = 0; j < m; ++j){
            getline(cin, t);
            t.erase(5, 1);
            t.erase(2, 1);
            bool done = false;
            for(int u = 1; u <= t.length(); ++u){
                if(u == t.length()){
                    ++a;
                    done = true;
                    break;
                }
                if(t[u] != t[u - 1]){
                    break;
                }
            }
            if(!done){
                for(int u = 1; u <= t.length(); ++u){
                    if(u == t.length()){
                        ++b;
                        done = true;
                        break;
                    }
                    if(t[u] >= t[u - 1]){
                        break;
                    }
                }
            }
            if(!done){
                ++c;
            }
        }
        mp[{i, s}] = {a, b, c};
        mx[0] = max(mx[0], a);
        mx[1] = max(mx[1], b);
        mx[2] = max(mx[2], c);
    }
    vector<string> str = {"If you want to call a taxi, you should call: ",
                          "If you want to order a pizza, you should call: ",
                          "If you want to go to a cafe with a wonderful girl, you should call: "};
    bool empty[3] = {true, true, true};
    for(auto p: mp){
        for(int i = 0; i < 3; ++i) {
            if (p.second[i] == mx[i]) {
                if (empty[i]) {
                    empty[i] = false;
                    str[i] += p.first.second;
                } else {
                    str[i] += ", " + p.first.second;
                }
            }
        }
    }
    for(int i = 0; i < 3; ++i){
        cout << str[i] << "." << endl;
    }
}