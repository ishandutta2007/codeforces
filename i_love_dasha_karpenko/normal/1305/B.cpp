#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E2+7;
const ll INF = 10E16;

ll A[DIM],B[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    string s;
    cin>>s;
    ll n = s.length();
    ll flag = 0;
    for(ll i = 1;i<n;i++){
        if (s[i]==')' && s[i-1]=='('){
            flag = 1;
            break;
        }
    }
    if (flag==0){
        cout<<"0\n";
        return 0;
    }
    ll cnt = 0;
    for(ll i = 0;i<n;i++){
        if (s[i]==')')
            cnt++;
    }
    ll del = 0;
    flag = 0;
    vector<ll> ans;
    for(ll i = 0;i<n;i++){
        if (del==cnt)flag = 1;
        if (flag==0){
            if (s[i]==')'){
                cnt--;
            }
            else{
                ans.pb(i+1);
                del++;
            }
        }
        else if (flag==1 && del>0){
            if (s[i]==')'){
                    ans.pb(i+1);
                    del--;
            }

        }
    }
    cout<<"1\n";
    cout<<ans.size()<<endl;
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
    return 0;
}