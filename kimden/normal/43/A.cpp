#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<string, int> mp;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        ++mp[s];
    }
    int mx = -1;
    string team;
    for(auto p: mp){
        if(p.second > mx){
            mx = p.second;
            team = p.first;
        }
    }
    cout << team << endl;
}