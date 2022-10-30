#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
const ll DIM = 1000+7;
const ll INF = 10e14;
const ll MOD = 1000000007;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)
struct node{
    ll fi,sc,num;
};
ll A[20];
ll di(ll x,ll y){
    ll res = 0;
    forn(i,4){
        if (x%10!=y%10)res++;
        x/=10;
        y/=10;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        map<ll,ll> S;
        forn(i,n){
            cin>>A[i];
            S[A[i]]++;

        }
        //sort(A+1,A+1+n);
        ll res = 0;
        vector<ll> ans;
        forn(i,n){
            if (S[A[i]]>1){
                ll num = -1,d = INF;
                for(ll i1 = 0;i1<10;i1++){
                    for(ll i2 = 0;i2<10;i2++){
                        for(ll i3 = 0;i3<10;i3++){
                            for(ll i4 = 0;i4<10;i4++){
                                if (S.count(i1*1000+i2*100+i3*10+i4)==0 && di(A[i],ll(i1*1000+i2*100+i3*10+i4))<d){
                                    num = ll(i1*1000+i2*100+i3*10+i4);
                                    d = di(A[i],ll(i1*1000+i2*100+i3*10+i4));
                                }
                            }
                        }
                    }
                }
                S[num]++;
                S[A[i]]--;
                res++;
                ans.pb(num);
            }
            else ans.pb(A[i]);
        }

        cout<<res<<endl;
        for(ll to:ans){
            if (to>=1000)cout<<to<<endl;
            else if (to>=100)cout<<'0'<<to<<endl;
            else if (to>=10)cout<<"00"<<to<<endl;
            else cout<<"000"<<to<<endl;
        }
    }
    return 0;
}