#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e3+10;
string s[mn];
int n,m,t;
ll dis[mn][mn];
bool vis[mn][mn];
int dr[4]={1,0,-1,0},dc[4]={0,1,0,-1};
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++)cin>>s[i];
    queue<pii>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        bool gud=0;
        for(int k=0;k<4;k++){
            int ii=i+dr[k],jj=j+dc[k];
            if(ii<0||jj<0||ii>=n||jj>=m)continue;
            gud|=(s[i][j]==s[ii][jj]);
        }
        if(gud)dis[i][j]=0,q.push({i,j});
    }
    while(q.size()){
        int r=q.front().first,c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=n||nc>=m||nr<0||nc<0||dis[nr][nc]!=0x3f3f3f3f3f3f3f3f)continue;
            dis[nr][nc]=dis[r][c]+1,q.push({nr,nc});
        }
    }
    while(t--){
        int r,c;
        ll k;
        scanf("%d%d%lld",&r,&c,&k),r--,c--;
        if(dis[r][c]>k){
            printf("%c\n",s[r][c]);
        }
        else{
            if(((k-dis[r][c])&1))printf("%c\n",(char)(s[r][c]^1));
            else printf("%c\n",s[r][c]);
        }
    }
}