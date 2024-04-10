#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<pair<ll,ll> ,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E9;
ll A[DIM],pref[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for(ll i = 1;i<=n;++i){
        A[i] = i;
        pref[i] = pref[i-1]+A[i];
    }
    while(q--){
        ll type;
        cin>>type;
        if (type==1){
            ll l,r;
            cin>>l>>r;
            cout<<pref[r]-pref[l-1]<<endl;
        }
        else{
            ll left;
            cin>>left;
            ll lst = n+1;
            while(left){
                super_set S;
                ll factor = 1,num = 0,ptr = 1;
                ll last = n;
                for(ll i = n;i>=1;--i){
                    ll cnt = ll(S.size())-S.order_of_key({A[i],i});
                    ll add = cnt*factor;
                    if (add+num+1>left){

                        left-=num+1;
                        last = i;
                        break;
                    }
                    num+=add;
                    factor*=ptr++;
                    factor = min(INF,factor);
                    S.insert({A[i],i});
                }
                if (S.empty() || S.rbegin()->first<A[last])return 0;
                ll pos = S.upper_bound({A[last],last})->second;

                swap(A[last],A[pos]);
                if (last+1<n)
                sort(A+1+last,A+1+n);
                lst = min(lst,last);
            }
            for(ll i = lst;i<=n;++i){
                pref[i] = pref[i-1]+A[i];
            }
            //for(ll i = 1;i<=n;++i)cout<<A[i]<<' ';
            //cout<<endl;
        }
    }

    return 0;
}