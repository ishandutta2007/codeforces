#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dist[26][26];
ll dp[2000005];

const ll INF = 1000000000000000LL;

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i=1; i<n; i++){
        dist[s[i-1]-'a'][s[i]-'a']++;
        dist[s[i]-'a'][s[i-1]-'a']++;
    }
    for(int mask=1; mask<(1<<m); mask++){
        dp[mask] = INF;
    }
    for(int mask=0; mask<(1<<m); mask++){
        ll jos = 0;
        for(int i=0; i<m; i++){
            if(mask & (1<<i)){
                for(int j=0; j<m; j++){
                    if(!(mask & (1<<j))) jos += dist[i][j];
                }
            }
        }
        for(int i=0; i<m; i++){
            if(!(mask & (1<<i))){
                dp[mask | (1<<i)] = min(dp[mask | (1<<i)], dp[mask] + jos);
            }
        }
    }
    cout << dp[(1<<m)-1];
    return 0;
}