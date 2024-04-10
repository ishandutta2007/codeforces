#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll sum;

vector <int> graf[200005];
int val[200005];
int deg[200005];
ll dp[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> val[i];
        sum += val[i];
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int s;
    cin >> s;
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 1 && i != s) q.push(i);
    }
    ll mx = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        sum -= val[v];
        deg[v] = 0;
        //cout << v << endl;
        for(auto c : graf[v]){
            if(c == s) continue;
            if(deg[c]){
                deg[c]--;
                if(deg[c] == 1) q.push(c);
            }
            else{
                dp[v] = max(dp[v], dp[c]);
            }
        }
        dp[v] += val[v];
        mx = max(mx, dp[v]);
    }
    //cout << sum << " " << mx << endl;
    cout << sum + mx;
    return 0;
}