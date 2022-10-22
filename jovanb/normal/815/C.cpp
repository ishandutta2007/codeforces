#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[5005];
int d[5005];
int sz[5005];
int dp[5005][2];
int cost[5005];

const int INF = 1000000007;

int tren2[5005][2];

int b;

void mrg(vector <int> tren[2], int &tsz, int k){
    for(int i=0; i<=tsz; i++){
        tren2[i][0] = tren[0][i];
        tren2[i][1] = tren[1][i];
        tren[0][i] = tren[1][i] = INF;
    }
    tren[0][0] = tren[1][0] = 0;
    for(int i=0; i<=k; i++){
        for(int j=0; j<=tsz; j++){
            tren[1][i+j] = min(tren[1][i+j], min(tren2[j][1], tren2[j][0]) + min(dp[i][0], dp[i][1]));
            tren[0][i+j] = min(tren[0][i+j], tren2[j][0] + dp[i][0]);
        }
    }
    tsz += k;
}

int res = 0;

void dfs(int v){
    sz[v] = 1;
    vector <int> tren[2];
    tren[1].push_back(0);
    tren[0].push_back(0);
    int tsz = 0;
    for(int i=1; i<=5000; i++){
        tren[0].push_back(INF);
        tren[1].push_back(INF);
    }
    for(auto c : graf[v]){
        dfs(c);
        sz[v] += sz[c];
        mrg(tren, tsz, sz[c]);
    }
    for(int j=1; j<=sz[v]; j++){
        dp[j][0] = min(tren[0][j-1] + cost[v], tren[0][j]);
        dp[j][1] = min(INF, min(tren[1][j-1], tren[0][j-1]) + cost[v] - d[v]);
    }
    for(int j=1; j<=sz[v]; j++){
        if(dp[j][0] <= b || (v == 1 && dp[j][1] <= b)){
            res = max(res, j);
        }
    }
    tren[1].clear();
    tren[0].clear();
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n >> b;
    cin >> cost[1] >> d[1];
    for(int i=2; i<=n; i++){
        int x;
        cin >> cost[i] >> d[i] >> x;
        graf[x].push_back(i);
    }
    dfs(1);
    cout << res;
    return 0;
}