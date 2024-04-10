//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
ll n,u,r,d,l;
ll Ch(ll a,ll b,ll c,ll dd){
    ll L = l,R = r,D = d,U = u;
    if (a){
        U--;
        L--;
    }
    if (b){
        U--;
        R--;
    }
    if (c){
        D--;
        R--;
    }
    if (dd){
        D--;
        L--;
    }
    if (0<=L && L<=n-2 && 0<=D && D<=n-2 && 0<=U && U<=n-2 && 0<=R && R<=n-2  )
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>u>>r>>d>>l;
        ll flag = 0;
        for(ll a = 0;a<2;++a)
            for(ll b = 0;b<2;++b)
                for(ll c = 0;c<2;++c)
                    for(ll d = 0;d<2;++d)
                        if (Ch(a,b,c,d))
                            flag = 1;
        if (flag==0)cout<<"No\n";
        else cout<<"Yes\n";
    }



    return 0;
}