#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e6+10;
ll d[mn];
int nxt[mn];
int bac[mn];
vector<int>kil[mn];
#define last(v) ((v)[(v).size()-1])
bool bad(pll a,pll b,pll c){return 1.*(c.second-a.second)/(a.first-c.first)<=1.*(b.second-a.second)/(a.first-b.first);}
bool bad(int a,int b,int c){
    return bad({-a,d[a]},{-b,d[b]},{-c,d[c]});
}
double gt(int a,int b){
    return 1.*(d[a]-d[b])/(a-b);
}
double ans[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",d+i);
    for(int i=1;i<=n;i++)d[i]+=d[i-1];
    vector<int>cvx;
    cvx.push_back(1);
    for(int i=2;i<=n;i++){
        while(cvx.size()>=2&&bad(cvx[cvx.size()-2],cvx[cvx.size()-1],i)){
            kil[i].push_back(cvx[cvx.size()-1]);
            nxt[cvx[cvx.size()-1]]=i;
            cvx.pop_back();
        }
        bac[i]=cvx[cvx.size()-1];
        nxt[cvx[cvx.size()-1]]=i;
        cvx.push_back(i);
    }
    int cur=1,q=0;
    while(q<n){
        while(nxt[cur]&&gt(q,cur)>=gt(q,nxt[cur]))cur=nxt[cur];
        for(int i=q+1;i<=cur;i++)ans[i]=gt(q,cur);
        q=cur;
        cur++;
    }
    for(int i=1;i<=n;i++)printf("%.9lf\n",ans[i]);
}