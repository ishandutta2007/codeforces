#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
int T;
int N,M;
 
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        char sas[N][M];
        bool bad[N][M], vis[N][M];
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){bad[i][j] = 0; vis[i][j] = 0;}
        for(int i = 0; i < N; i++)cin >> sas[i];
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            if(sas[i][j] == 'G' || sas[i][j] == '.')continue;
            bad[i][j] = 1;
            if(sas[i][j] == '#')continue;
            if(i > 0)bad[i-1][j] = 1;
            if(j > 0)bad[i][j-1] = 1;
            if(j < M-1)bad[i][j+1] = 1;
            if(i < N-1)bad[i+1][j] = 1;
        }
        bool k = 0;
        //for(int i = 0; i < N; i++){for(int j = 0; j < M; j++){cout << bad[i][j];}cout << "\n";}
        queue <pii> q; q.push({N-1,M-1});
        int x, y;
        while(!q.empty()){
            x = q.front().fi; y = q.front().se;
            q.pop();
            vis[x][y] = 1;
            if(bad[x][y])break;
            if(x > 0 && vis[x-1][y]==0 && bad[x-1][y] ==0){q.push({x-1,y});vis[x-1][y]=1;}
            if(x < N-1 && vis[x+1][y]==0 && bad[x+1][y] == 0){q.push({x+1,y});vis[x+1][y]=1;}
            if(y > 0 && vis[x][y-1]==0 && bad[x][y-1]==0){q.push({x,y-1});vis[x][y-1]=1;}
            if(y < M-1 && vis[x][y+1]==0 && bad[x][y+1]==0){q.push({x,y+1});vis[x][y+1]=1;}
        }
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
            if(sas[i][j] == 'G' && vis[i][j] == 0)k = 1;
        }//cout <<"VISSS\n";
    //    for(int i = 0; i < N; i++){for(int j = 0; j < M; j++){cout << vis[i][j];}cout << "\n";}
    //    for(int i = 0; i < N; i++){for(int j = 0; j < M; j++){cout << sas[i][j];}cout << "\n";}
        if(k)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}