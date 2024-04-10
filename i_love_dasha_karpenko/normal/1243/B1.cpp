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
       ll cnt = 0;
       vector<pair<char,char> > V;
       for(ll i = 0;i<s1.length();i++){
            if (s1[i]!=s2[i]){
                cnt++;
                V.pb({s1[i],s2[i]});
            }
       }
       if ((cnt==2 && V[0].fi==V[1].fi && V[1].sc==V[0].sc) || cnt==0){
        cout<<"Yes\n";
       }
       else{
        cout<<"No\n";
       }
    }
    return 0;
}