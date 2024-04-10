#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(int a, int b){
    return abs(a)<abs(b);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int>choices;
    for(int i = -200000; i<=200000; i++){
        choices.push_back(i);
    }
    sort(choices.begin(),choices.end(),comp);
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        vector<int>ans(n+1);
        priority_queue<pair<int,int>>pq;
        for(int i = 1; i<=n; i++){
            pq.push({arr[i],i});
        }
        for(int i = 1; i<=n; i++){
            pair<int,int>p = pq.top(); pq.pop();
            ans[p.second] = choices[i];
        }
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            cnt+=abs(ans[i])*arr[i];
        }
        cout << cnt*2 << "\n";
        for(int i = 0; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}