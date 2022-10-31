#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 10+1;
const ll INF = 1e8;
ll cnt[30],cnt1[30];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        memset(cnt1,0,sizeof(cnt1));
        ll n;
        cin>>n;

        string s;
        cin>>s;
        ll res = 0;
        for(ll i = 0;i<s.length();i++){
            for(ll j = 0;j<s[i]-'a';++j)res+=cnt[j];
            ++cnt[s[i]-'a'];
        }

        ll res1 = 0;
        cin>>s;

        for(ll i = 0;i<s.length();i++){
            for(ll j = 0;j<s[i]-'a';++j)res1+=cnt1[j];
            ++cnt1[s[i]-'a'];
        }
        ll flag = 0,ff = 0;
        for(ll i = 0;i<=29;++i){
            if (cnt[i]!=cnt1[i]){
                res = 1;
                res1 = 0;
                flag = 1;
                break;
            }
            if (cnt1[i]>1)ff = 1;
        }
        if (flag == 0 && (res%2==res1%2|| ff==1))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}