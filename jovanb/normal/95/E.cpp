#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int cnt[N+5];
int dp[N+5];
bool visited[N+5];
vector <int> graf[N+5];

int cc;

void dfs(int v){
    visited[v] = 1;
    cc++;
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
}

bool lucky(int x){
    while(x){
        if(x%10 != 4 && x%10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cc = 0;
            dfs(i);
            cnt[cc]++;
        }
    }
    for(int i=1; i<=n; i++) dp[i] = 2*N;
    for(int j=1; j<=n; j++){
        if(cnt[j] == 0) continue;
        for(int d=0; d<j; d++){
            int t = (n/j)*j + d;
            if(t > n) t -= j;
            if(t < 0) continue;
            deque <pair <int, int>> dq;
            dq.push_front({t, dp[t] - (t-d)/j});
            for(int i=t; i>=1; i-=j){
                while(!dq.empty() && dq.front().first - j >= 0 && i - (dq.front().first - j) <= j*cnt[j]){
                    int k = dq.front().first - j;
                    int f = dp[k] - (k-d)/j;
                    while(!dq.empty() && dq.front().second >= f) dq.pop_front();
                    dq.push_front({k, f});
                }
                while(!dq.empty() && dq.back().first >= i) dq.pop_back();
                if(dq.empty()) continue;
                dp[i] = min(dp[i], dq.back().second + (i-d)/j);
            }
        }
    }
    int res = 2*N;
    for(int i=1; i<=n; i++){
        if(lucky(i) && dp[i] != 2*N) res = min(res, dp[i] - 1);
    }
    if(res == 2*N) cout << "-1\n";
    else cout << res << "\n";
    return 0;
}