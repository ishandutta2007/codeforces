#include<bits/stdc++.h>
using namespace std;
bool vis[40010];
int N , M , K , num[110] , cnt[20] , minDis[40010] , minN[31][31] , dp[1 << 21 + 1] , cnt1[1 << 21 + 1];
queue < int > q;

inline void Dijk(int dir){
    memset(minDis , 0x3f , sizeof(minDis));
    minDis[cnt[dir]] = 0;
    q.push(cnt[dir]);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 1 ; i <= K ; i++){
            if(t + num[i] <= N + 1 && minDis[t + num[i]] > minDis[t] + 1){
                minDis[t + num[i]] = minDis[t] + 1;
                q.push(t + num[i]);
            }
            if(t - num[i] > 0 && minDis[t - num[i]] > minDis[t] + 1){
                minDis[t - num[i]] = minDis[t] + 1;
                q.push(t - num[i]);
            }
        }
    }
    for(int i = 1 ; i <= cnt[0] ; i++)
        minN[dir][i] = minDis[cnt[i]];
}

int main(){
    cin >> N >> M >> K;
    for(int i = 1 ; i <= M ; i++){
        int a;
        cin >> a;
        vis[a] = 1;
    }
    for(int i = 1 ; i <= N + 1 ; i++)
        if(vis[i] ^ vis[i - 1])
            cnt[++cnt[0]] = i;
    if(cnt[0] == 0){
        cout << 0;
        return 0;
    }
    for(int i = 1 ; i <= K ; i++)
        cin >> num[i];
    for(int i = 1 ; i <= cnt[0] ; i++)
        Dijk(i);
    for(int i = 1 ; i < 1 << cnt[0] ; i++)
        cnt1[i] = cnt1[i - (i & -i)] + 1;
    memset(dp , 0x3f , sizeof(dp));
    dp[0] = 0;
    for(int i = 0 ; i < (1 << cnt[0]) ; i++)
        if(!(cnt1[i] & 1)){
            int t = ((1 << cnt[0]) - 1) ^ i;
            if(t == 0){
                cout << (dp[i] == 0x3f3f3f3f ? -1 : dp[i]);
                return 0;
            }
            t = log2(t & -t) + 1;
            for(int j = t + 1 ; j <= cnt[0] ; j++)
                if(!(i & (1 << j - 1)))
                    dp[i | (1 << t - 1) | (1 << j - 1)] = min(dp[i | (1 << t - 1) | (1 << j - 1)] , dp[i] + minN[t][j]);
        }
    return 0;
}