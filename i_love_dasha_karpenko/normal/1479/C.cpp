#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
const ll DIM = 1E6+7;
struct node{
    ll u,v,w;
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll L,R;
    cin>>L>>R;
    vector<node> edges;
    R-=L-1;
    ll base_add = L;
    ll mult = 1,cnt = 0;
    while(mult*2<=R){
        mult*=2;
        ++cnt;
    }
    for(ll i = 1;i<=1+cnt;++i){
        for(ll j = i+1;j<=1+cnt;++j){
            edges.push_back({i,j,1ll<<(j-2)});
        }
    }
    ll add = mult;
    ll last = cnt+1;
    while(R>add){
        mult = 1,cnt = 0;
        while(mult*2-1<=R-add){
            mult*=2;
            ++cnt;
        }
        for(ll i = 2;i<=1+cnt;++i){
            edges.push_back({i,last+1,add-1});
        }
        add+=mult-1;
        ++last;
    }
    for(ll i = 1;i<=last;++i){
        edges.push_back({i,last+1,base_add});
    }
    cout<<"YES\n";
    cout<<last+1<<' '<<edges.size()<<endl;
    for(auto to:edges)cout<<to.u<<' '<<to.v<<' '<<to.w<<endl;
    return 0;
}