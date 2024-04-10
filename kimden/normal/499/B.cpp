#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    string s, t;
    for(int i = 0; i < m; ++i){
        cin >> s >> t;
        if(s.length() <= t.length()){
            mp[s] = s;
        }else{
            mp[s] = t;
        }
    }
    for(int i = 0; i < n; ++i){
        cin >> s;
        if(i){
            cout << " ";
        }
        cout << mp[s];
    }
    cout << endl;
}