#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    map<int, set<int>> mp;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        mp[c[i]].size();
    }
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        --x;
        --y;
        if(c[x] != c[y]){
            mp[c[x]].insert(c[y]);
            mp[c[y]].insert(c[x]);
        }
    }
    int mx = -1;
    int idx = -1;
    for(auto p: mp){
        if((int)p.second.size() > mx){
            mx = p.second.size();
            idx = p.first;
        }
    }
    cout << idx << endl;

}