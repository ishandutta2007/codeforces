#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e3+10;
int bes[mn][mn];
string g[mn];
int n,m;
bool pos(int a,int b){
    return a>=0&&b>=0&&a<n&&b<m&&g[a][b]!='#';
}
deque<pii>q;
void go(int a,int b,int v){
    if(!pos(a,b))return;
    if(bes[a][b]!=0x1f1f1f1f)return;
    if(g[a][b]=='.'){
        bes[a][b]=v+1;
        q.push_back({a,b});
    }
    else{
        bes[a][b]=v;
        q.push_front({a,b});
    }
}
int aa,bb;
void setup(int tar){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(pos(i,j)&&g[i][j]!='.'){
                if(g[i][j]-'1'!=tar)continue;
                bes[i][j]=0;
                aa=i,bb=j;
                q.push_back({i,j});
                return;
            }
        }
    }
}
int ans[mn][mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>g[i];
    memset(bes,0x1f,sizeof(bes));
    setup(0);
    while(q.size()){
        int a=q.front().first,b=q.front().second;
        q.pop_front();
        go(a+1,b,bes[a][b]);
        go(a-1,b,bes[a][b]);
        go(a,b+1,bes[a][b]);
        go(a,b-1,bes[a][b]);
    }
    for(i=0;i<n;i++)for(j=0;j<m;j++)ans[i][j]+=bes[i][j];
    memset(bes,0x1f,sizeof(bes));
    setup(1);
    while(q.size()){
        int a=q.front().first,b=q.front().second;
        q.pop_front();
        go(a+1,b,bes[a][b]);
        go(a-1,b,bes[a][b]);
        go(a,b+1,bes[a][b]);
        go(a,b-1,bes[a][b]);
    }
    for(i=0;i<n;i++)for(j=0;j<m;j++)ans[i][j]+=bes[i][j];
    memset(bes,0x1f,sizeof(bes));
    setup(2);
    while(q.size()){
        int a=q.front().first,b=q.front().second;
        q.pop_front();
        go(a+1,b,bes[a][b]);
        go(a-1,b,bes[a][b]);
        go(a,b+1,bes[a][b]);
        go(a,b-1,bes[a][b]);
    }
    for(i=0;i<n;i++)for(j=0;j<m;j++)ans[i][j]+=bes[i][j];
    int pr=0x3f3f3f3f;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(g[i][j]=='.')ans[i][j]-=2;
    for(i=0;i<n;i++)for(j=0;j<m;j++)pr=min(pr,ans[i][j]);
    if(pr>1000000)printf("-1");
    else printf("%d",pr);
}