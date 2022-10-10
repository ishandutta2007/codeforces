#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,x[maxn],p[maxn],u[maxn];
ll w[maxn],s1[maxn],s2[maxn];
vector<int>V[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)V[i].clear();
        for(i=1;i<=n;i++)scanf("%d%d",&x[i],&p[i]),u[i]=x[i];
        sort(u+1,u+1+n);k=unique(u+1,u+1+n)-u-1;
        for(i=1;i<=n;i++)x[i]=lower_bound(u+1,u+1+k,x[i])-u,V[x[i]].push_back(i);
        priority_queue<pair<int,int> >Q;
        ll Sum=0,d=0;
        for(i=1;i<=k;i++){
            while(!Q.empty() && u[i]>=-Q.top().first){
                auto t=Q.top();
                Sum-=p[t.second]-(u[i]-u[x[t.second]]);
                --d;Q.pop();
            }
            for(auto v:V[i]){
                Q.push(make_pair(-(u[x[v]]+p[v]),v));
                Sum+=p[v];
                ++d;
            }
            w[i]=Sum;
            // cerr<<"OK! "<<i<<' '<<Sum<<endl;
            if(i!=k)Sum-=d*(u[i+1]-u[i]);
        }while(!Q.empty())Q.pop();d=0;Sum=0;
        for(i=k;i>=1;i--){
            while(!Q.empty() && u[i]<=Q.top().first){
                auto t=Q.top();
                Sum-=p[t.second]-(u[x[t.second]]-u[i]);
                --d;Q.pop();
            }
            w[i]+=Sum;
            for(auto v:V[i]){
                Q.push(make_pair(u[x[v]]-p[v],v));
                Sum+=p[v];
                ++d;
            }
            if(i!=1)Sum-=d*(u[i]-u[i-1]);
        }while(!Q.empty())Q.pop();
        ll Now=-1e18;
        for(i=1;i<=k;i++)s1[i]=s2[i]=-1e18;
        for(i=1;i<=k;i++){
            // w[i] - max(0,p[j]-(x[j]-i)) <= m
            // w[i] - m - i <= p[j]-x[j]
            if(w[i]-m>0)Now=max(Now,w[i]-m-u[i]);
            s1[i]=Now;
            // cerr<<"i="<<i<<' '<<w[i]<<' '<<s1[i]<<endl;
        }Now=-1e18;
        for(i=k;i>=1;i--){
            // w[i] - max(0,p[j]-(i-x[j])) <= m
            // w[i] - m + i <= p[j]+x[j]
            if(w[i]-m>0)Now=max(Now,w[i]-m+u[i]);
            s2[i]=Now;
            // cerr<<"i="<<i<<' '<<w[i]<<' '<<s2[i]<<' '<<m<<endl;
        }
        for(i=1;i<=n;i++)
            if(p[i]-u[x[i]]>=s1[x[i]] && p[i]+u[x[i]]>=s2[x[i]])putchar('1');else putchar('0');
        puts("");
    }
}