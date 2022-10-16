#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, m; 
    cin >> n >> m;
    int arr[n + 5][m + 5];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            pq.push(mp(arr[i][j], mp(i, j)));
        }
    }
    int plan[n + 5][m + 5];
    memset(plan, -1,sizeof plan);
    for(int i = 0; i < m; i++) {
        auto t = pq.top();
        pq.pop();
        plan[t.se.fi][i] = t.fi;
        arr[t.se.fi][t.se.se] = -1;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(plan[j][i] != -1) continue;
                if(arr[j][k] != -1) {
                    plan[j][i] = arr[j][k];
                    arr[j][k] = -1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << plan[i][j] << ' ';
        cout << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    return 0;
}