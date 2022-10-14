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

int N,M,Q;
bool sas[1010][1010];
bool lul[1010][1010];
ll lel[1010][1010];
bool vis[1010][1010];
string a;
int main(){
    cin >> N >> M >> Q;
    for(int i = 0; i < N; i++){
        cin >> a;
        for(int j = 0; j < M; j++)sas[i][j]=(a[j]-'0');
    }
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
        lel[i][j] = 1e18+1;
        if(i > 0 && sas[i-1][j]==sas[i][j])lul[i][j] = 1;
        if(i < N-1 && sas[i+1][j]==sas[i][j])lul[i][j] = 1;
        if(j > 0 && sas[i][j-1]==sas[i][j])lul[i][j] = 1;
        if(j < M-1 && sas[i][j+1]==sas[i][j])lul[i][j] = 1;
        if(lul[i][j]){q.push({i,j});lel[i][j] = 0;vis[i][j] = 1;}
    }
    int x,y;
    while(!q.empty()){
        x = q.front().fi; y = q.front().se; q.pop();
        if(x > 0 && !vis[x-1][y]){
            lel[x-1][y] = lel[x][y] + 1;
            vis[x-1][y] = 1;
            q.push({x-1,y});
        }
        if(x < N-1 && !vis[x+1][y]){
            lel[x+1][y] = lel[x][y] + 1;
            vis[x+1][y] =1;
            q.push({x+1,y});
        }
        if(y > 0 && !vis[x][y-1]){
            vis[x][y-1] = 1;
            lel[x][y-1] = lel[x][y] + 1;
            q.push({x,y-1});
        }
        if(y < M-1 && !vis[x][y+1]){
            vis[x][y+1] = 1;
            lel[x][y+1] = lel[x][y] + 1;
            q.push({x,y+1});
        }
    }
    ll s;
    //for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){cout << lel[i][j] << " \n"[j == M-1];}
    while(Q--){
        cin >> x >> y >> s;
        x--; y--;
        if(s < lel[x][y])cout << sas[x][y] << "\n";
        else cout << (sas[x][y]^((s-lel[x][y])&1))<<"\n";
    }
    return 0;
}