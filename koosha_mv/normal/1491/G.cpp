#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,u,v,x,a[N],mark[N];
set<int> s;
vector<pair<int,int> > ans;

void dfs(int x){
    int sz=s.size();
    s.erase(x);
    if(s.size()==sz) return ;
    dfs(a[x]);
}
void op(int u,int v){
    swap(a[u],a[v]);
    ans.pb(mp(u,v));
}
void solve(int u,int v){
    while(a[u]!=v) op(u,a[u]);
    while(a[v]!=u) op(v,a[v]);
    op(u,v);
}

int main(){
    cin>>n;
    f(i,1,n+1){ 
        cin>>a[i];
        s.insert(i);
    }
    while(s.size()){
        u=*s.begin();
        dfs(u);
        if(s.size()){
            v=*s.begin();
            dfs(v);
            op(u,v);
            solve(u,v);
        }
        else{
            if(a[u]!=u){
                if(a[a[u]]==u){
                    x=1;
                    v=a[u];
                    while(x==a[u] || x==a[a[u]]) x++;
                    op(x,u);
                    op(x,v);
                    op(x,u);
                }
                else{
                    x=a[u];
                    v=a[a[u]];
                    op(u,x);
                    op(x,v);
                    v=x;
                    solve(u,v);
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    f(i,0,ans.size()) cout<<ans[i].F<<" "<<ans[i].S<<endl;;
}