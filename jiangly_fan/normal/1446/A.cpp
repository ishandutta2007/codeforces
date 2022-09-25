#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        LL W;
        cin >> n >> W;
        vector<pair<LL, int>> w(n);
        for(int i = 0; i < n; i += 1){
            cin >> w[i].first;
            w[i].second = i + 1;
        }
        sort(w.begin(), w.end(), greater<pair<LL, int>>());
        vector<int> v;
        LL C = 0;
        for(int i = 0; i < n; i += 1){
            if(C + w[i].first > W) continue;
            C += w[i].first;
            v.push_back(w[i].second);
        }
        if(C >= (W + 1) / 2){
            cout << v.size() << "\n";
            for(int x : v) cout << x << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}