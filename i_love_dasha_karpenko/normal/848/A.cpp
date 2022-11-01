#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
ll k;
pp num[DIM];
int main()
{

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>k;
    if (k==0){
        cout<<'a'<<endl;
        return 0;
    }

    ll pos = 0,pref = 0;
    forn(i,k+INF){
        if (pos>k)break;
        while(pref+i>pos && pos<=k){
            num[pos] = {pref,i};
            pos++;
        }
        pref+=i;
    }
    ll let = 0;
    for(char i = 'a';i<='z';i++){
        if (k==0)break;
        pp a = num[k];
        k-=a.fi;
        forn(i,a.sc)cout<<char(let+'a');
        let++;
    }
    cout<<endl;
    return 0;
}
// 1100
//