#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=534;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn][mn],r[mn],c[mn],res[mn][mn];
pii pos[mn*mn];
bool u[mn*mn],vis[mn][mn];
vector<pii>g[mn][mn];
struct comp{
    bool operator()(pii a,pii b){
        return min(r[a.first],c[a.second])<min(r[b.first],c[b.second]);
    }
};
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            r[i]=max(r[i],a[i][j]);
            c[j]=max(c[j],a[i][j]);
        }
    sort(r,r+n,greater<int>());
    sort(c,c+m,greater<int>());
    memset(a,0,sizeof(a));
    int ci=0,cj=0;
    for(int i=0,j=0;i<n||j<m;){
        if(1){
            if(r[i]>c[j]) {
                i++;
                u[r[i-1]] = 1;
                vis[i-1][j-1] = 1;
                a[i-1][j-1] = r[i-1];
                pos[r[i-1]] = {i-1, j-1};
            }
            else{
                if(r[i]==c[j])i++;
                j++;
                u[c[j-1]]=1;
                vis[i-1][j-1]=1;
                a[i-1][j-1]=c[j-1];
                pos[c[j-1]]={i-1,j-1};
            }
            ci=i-1,cj=j-1;
            for(int ii=ci;ii+1<n;ii++)g[ii][cj].push_back({ii+1,cj}),res[ii+1][cj]++;
            for(int ii=ci;ii-1>=0;ii--)g[ii][cj].push_back({ii-1,cj}),res[ii-1][cj]++;
            for(int jj=cj;jj+1<m;jj++)g[ci][jj].push_back({ci,jj+1}),res[ci][jj+1]++;
            for(int jj=cj;jj-1>=0;jj--)g[ci][jj].push_back({ci,jj-1}),res[ci][jj-1]++;
        }
    }
    priority_queue<pii,vector<pii>,comp>pq;
    for(int v=n*m;v;v--){
            pii p;
            if(!u[v]){
                u[v]=1;
                p=pq.top();
                pq.pop();
                vis[p.first][p.second]=1;
                a[p.first][p.second]=v;
                pos[v]=p;
            }
            else p=pos[v];
            for(pii q:g[p.first][p.second]){
                res[q.first][q.second]--;
                if(!res[q.first][q.second]&&!vis[q.first][q.second]){
                    pq.push(q);
                }
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
}