#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>>arr(n+1);
    for(int i = 1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        arr[i] = {x,y};
    }
    vector<pair<int,int>>low;
    vector<pair<int,int>>high;
    for(int i = 1; i<=n; i++){
        if(arr[i].first<arr[i].second){
            low.push_back({arr[i].first,i});
        }
        else{
            high.push_back({arr[i].first,i});
        }
    }
    sort(low.begin(),low.end());
    sort(high.begin(),high.end());
    reverse(low.begin(),low.end());
    if(low.size()>high.size()){
        cout << low.size() << "\n";
        for(auto nxt: low){
            cout << nxt.second << " ";
        }
        cout << "\n";
    }
    else{
        cout << high.size() << "\n";
        for(auto nxt: high){
            cout << nxt.second << " ";
        }
        cout << "\n";
    }
    return 0;
}