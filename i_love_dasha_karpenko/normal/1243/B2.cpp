#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define endl '\n'
#define x1 dsfdsfdsfewewer
#define y1 fdgretdfdsfgddsf
const ll DIM = 2*(10e4)+7;
const ll INF = 10e16;
const ll MOD = (10e9)+7;
const ll _MAX = (10e8)+7;
/*                       */

ll t;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout<<_MAX<<endl;
    cin>>t;
    forn(query,t){
        ll n; cin>>n;
       string s1,s2;
       cin>>s1>>s2;
       vector<pp> ans;
       ll flag = 0;
       for(ll i = 0;i<s1.length();i++){
            if (s1[i]==s2[i])continue;
            ll rev = -1,nor = -1;
            for(ll j = i+1;j<n;j++){
                if (s1[j]==s1[i]){
                    nor = j;
                    break;
                }
                if (s2[j]==s1[i]){
                    rev = j;
                }
            }
            if (nor==-1){
                if(rev==-1){
                    flag = 1;
                    break;
                }
                ans.pb({rev,rev});
                swap(s1[rev],s2[rev]);
                ans.pb({rev,i});
                swap(s1[rev],s2[i]);
            }
            else{
                ans.pb({nor,i});
                swap(s1[nor],s2[i]);
            }
       }
       if (flag==1){
        cout<<"No\n";
       }
       else{
        cout<<"Yes\n";
        cout<<ans.size()<<endl;
        for(pp to:ans)cout<<to.fi+1<<' '<<to.sc+1<<endl;
       }
    }
    return 0;
}