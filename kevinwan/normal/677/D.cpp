#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};
int a[300][300],d[300][300];
vector<pii>num[90001];
vector<int>c[90001];
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        scanf("%d",&a[i][j]);
        num[a[i][j]].push_back({i,j});
    }
    for(auto&x:num[1])c[1].push_back(x.first+x.second);
    for(int i=1;i<p;i++){
        if(num[i].size()*num[i+1].size()<=n*m*10){
            c[i+1].assign(num[i+1].size(),0x3f3f3f3f);
            for(int j=0;j<num[i].size();j++){
                for(int k=0;k<num[i+1].size();k++){
                    c[i+1][k]=min(c[i+1][k],c[i][j]+abs(num[i+1][k].first-num[i][j].first)+abs(num[i+1][k].second-num[i][j].second));
                }
            }
        }
        else{
            memset(d,0x3f3f3f3f,sizeof(d));
            vector<pair<int,pii>>v;
            for(int j=0;j<num[i].size();j++)v.push_back({c[i][j],num[i][j]});
            sort(v.begin(),v.end());
            deque<pii>q;
            int cur=0;
            while(q.size()||cur!=v.size()){
                while(cur!=v.size()&&(q.empty()||v[cur].first<=d[q.front().first][q.front().second])){
                    if(d[v[cur].second.first][v[cur].second.second]==0x3f3f3f3f)q.push_front(v[cur].second),d[v[cur].second.first][v[cur].second.second]=v[cur].first;
                    cur++;
                }
                int r=q.front().first,c=q.front().second;
                q.pop_front();
                for(int j=0;j<4;j++){
                    if(r+dr[j]>=n||r+dr[j]<0||c+dc[j]>=m||c+dc[j]<0)continue;
                    if(d[r+dr[j]][c+dc[j]]!=0x3f3f3f3f)continue;
                    q.push_back({r+dr[j],c+dc[j]}),d[r+dr[j]][c+dc[j]]=d[r][c]+1;
                }
            }
            for(int j=0;j<num[i+1].size();j++)c[i+1].push_back(d[num[i+1][j].first][num[i+1][j].second]);
        }
    }
    printf("%d",c[p][0]);

}