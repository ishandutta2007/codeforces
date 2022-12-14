#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ind(n);
        vector<vector<int>> way(n);
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            ind[i] = x;
            while(x--){
                int num; cin >> num; --num;
                way[num].push_back(i);
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; ++i){
            if(!ind[i]){
                pq.push({1, i});
            }
        }
        int ans = -1;
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            ans = top.first;
            for(auto&nxt:way[top.second]){
                --ind[nxt];
                if(!ind[nxt]){
                    pq.push({top.first + (nxt < top.second), nxt});
                }
            }
        }
        int no = 0;
        for(int i = 0; i < n; ++i){
            if(ind[i]){
                cout << "-1\n";
                no = 1;
                break;
            }
        }
        if(no) continue;
        cout << ans << '\n';
    }
    return 0;
}