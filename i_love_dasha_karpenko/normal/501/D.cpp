#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 1E6+7;
const ll INF = 1E18;
ll n,T[DIM],cnt[DIM];
void add(ll pos,ll delta){
    ++pos;
    for(ll i = pos;i<DIM;i+=(i&-i))
        T[i]+=delta;
}
ll get(ll pos){
    ++pos;
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i))
        ret+=T[i];
    return ret;
}
ll ord(vector<ll> &V){
    memset(T,0,sizeof(T));
    for(ll i = n-1;i>=0;--i){
        cnt[i]+=get(V[i]);
        add(V[i],1);
    }
}
void perm(){

    for(ll i = n-1;i>=0;--i){
        if (i==0)cnt[i]%=n;
        else{
            cnt[i-1]+=cnt[i]/(n-i);
            cnt[i]%=(n-i);
        }
    }
    super_set S;
    for(ll i = 0;i<n;++i)
        S.insert(i);
    for(ll i = 0;i<n;++i){
        cout<<*S.find_by_order(cnt[i])<<' ';
        S.erase(S.find_by_order(cnt[i]));
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    vector<ll> V1(n),V2(n);
    for(ll i = 0;i<n;++i)
        cin>>V1[i];
    for(ll i = 0;i<n;++i)
        cin>>V2[i];
    ord(V1);
    ord(V2);
    perm();
    return 0;
}