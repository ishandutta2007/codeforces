#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << "? 1" << endl;
    vector<int> d(n + 1);
    set<pair<int, int>> sp;
    auto add = [&](int x, int y){
        if(x > y) swap(x, y);
        sp.insert({x, y});
    };
    for(int i = 1; i <= n; i += 1){
        cin >> d[i];
        if(d[i] == 1) add(1, i);
    }
    vector<int> v[2];
    for(int i = 2; i <= n; i += 1) v[d[i] & 1].push_back(i);
    if(v[0].size() > v[1].size()) swap(v[0], v[1]);
    for(int x : v[0]){
        cout << "? " << x << endl;
        for(int i = 1; i <= n; i += 1){
            cin >> d[i];
            if(d[i] == 1) add(x, i);
        }
    }
    cout << "!" << endl;
    for(auto [x, y] : sp) cout << x << " " << y << endl;
    return 0;
}