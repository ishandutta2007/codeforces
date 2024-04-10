#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
#define db double
#define INF 0x3f3f3f3f
using namespace std;
#define pii pair<int,int>
vector<pii> g;
signed main(){
    int n;
    si(n);
    g.push_back(make_pair(1,2e9));
    rep(i,1,n){
        sort(g.begin(),g.end());
        int a,b;
        si(a);
        si(b);
        int r=a+b-1;
        int fl=0;
        for(int kk=0;kk<g.size();kk++){
            auto j=g[kk];
            if(j.first<=a&&j.second>=r){
                fl=1;
                printf("%d %d\n",a,r);
                int ll=j.first,rr=a-1;
                int lll=r+1,rrr=j.second;
                g[kk]=make_pair(ll,rr);
                if(lll<=rrr){
                    g.push_back(make_pair(lll,rrr));
                }
                break;
            }
        }
        if(fl)continue;
        rep(j,0,g.size()-1){
            if(g[j].second-g[j].first+1>=b){
                printf("%d %d\n",g[j].first,g[j].first+b-1);
                g[j].first+=b;
                break;
            }
        }
    }
    return 0;
}