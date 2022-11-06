#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    set<int>s;
    for(int i = 1; i<=(int)1e5; i++){
        s.insert(i*i);
        s.insert(i*i*i);
    }
    vector<int>arr;
    for(int nxt: s){
        arr.push_back(nxt);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int idx = upper_bound(arr.begin(),arr.end(),n)-arr.begin();
        cout << idx << "\n";
    }
    return 0;
}