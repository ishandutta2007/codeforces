#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,k; ll dp[210][210][55],tmp[55];
queue<int> que[210]; vector<int> lst[210],nxt[210];
struct node{
    ll x,y;
    node(){}
    node(ll _x,ll _y):x(_x),y(_y){}
    node operator-(const node &a) const{ return node(x-a.x,y-a.y);} 
    bool operator<(const node &a) const{ return x<a.x||x==a.x&&y<a.y;}
} p[210],q[210];
ll cross(const node &a,const node &b){ return 1ll*a.x*b.y-1ll*a.y*b.x;}
bool cmp(const node &a,const node &b){ return cross(a,b)>0;}
void update(int x,int y){
    while (!que[x].empty()&&cross(q[que[x].front()]-q[x],q[y]-q[x])<0){
        update(que[x].front(),y);
        que[x].pop();
    }
    lst[x].push_back(y); nxt[y].push_back(x); que[y].push(x);
}
int main(){
    cin>>n>>k; int x,y;
    for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    sort(p+1,p+n+1);

	ll ans=0;
    for (int i=1;i<=n;i++){
        int cnt=0;
        for (int j=i+1;j<=n;j++) q[++cnt]=p[j]-p[i];
        sort(q+1,q+cnt+1,cmp);
        for (int u=1;u<cnt;u++) update(u,u+1);
        for (int u=cnt;u>=1;u--){
    		for (int j=1;j<k;j++) tmp[j]=-INF;
			reverse(nxt[u].begin(),nxt[u].end());
            for (int v:nxt[u]){
                dp[u][v][1]=cross(q[v],q[u]);
                while (!lst[u].empty()&&cross(q[v]-q[u],q[lst[u].back()]-q[u])<0){
                    for (int j=1;j<k;j++) tmp[j]=max(tmp[j],dp[lst[u].back()][u][j]);
                    lst[u].pop_back();
                }
                for (int j=1;j<k;j++) dp[u][v][j+1]=tmp[j]+cross(q[v],q[u]);
	            ans=max(ans,dp[u][v][k-2]);
            }
            lst[u].clear(); nxt[u].clear();
            while (!que[u].empty()) que[u].pop();
        }
    }
    cout<<ans/2<<'.'<<ans%2*5<<"0\n";
    return 0;
}