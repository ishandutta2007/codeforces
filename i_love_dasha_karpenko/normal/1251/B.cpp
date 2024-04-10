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
const ll DIM = (10e4)+7;
const ll INF = 10e16;
const ll MOD = (10e9)+7;
/*                       */

ll t;
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    forn(query,t){
        ll n; cin>>n;
        //vector<ll> V;
        ll cnt1 = 0,cnt0 = 0,sum = 0;
        vector<ll> r1,r2;
        forn(i,n){
            string s;
            cin>>s;
            //cout<<s<<endl;
            sum+=s.length();
            if (s.length()%2==0)r2.pb(ll(s.length()));
            else r1.pb(ll(s.length()));
            for(ll j = 0;j<s.length();j++){
                if (s[j]=='0')cnt0++;
                else cnt1++;
            }
        }
        //cout<<sum<<endl;
        ll pairs1 = cnt1/2,pairs2 = cnt0/2;
        ll p = pairs1+pairs2;
        sort(r2.begin(),r2.end(),greater<ll>());
        ll res = 0;
        while(!r2.empty()){
            if (p<r2.back()/2)break;
            p-=r2.back()/2;
             sum-=r2.back();
            r2.pop_back();
            //cout<<r2.back()<<" csdfds\n";
           
            
            res++;
        }
        sort(r1.begin(),r1.end(),greater<ll>());
        while(!r1.empty()){
            
            if (r1.back()/2>p)break;
            p-=(r1.back()/2);
            //cout<<sum<<' '<<" fleks\n";
            if (sum>=r1.back())sum-=r1.back();
            else break;
            r1.pop_back();
            res++;
            
        }
        cout<<res<<endl;
    }
    return 0;
}