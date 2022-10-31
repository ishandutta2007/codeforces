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
        string s;
        cin>>s;
        vector<ll> V1,V2;
        for(ll i = 0;i<s.length();i++){
            ll num = s[i]-'0';
            if (num%2==0)V1.pb(num);
            else V2.pb(num);
        }
        reverse(V1.begin(),V1.end());
        reverse(V2.begin(),V2.end());
        while(!V1.empty() || !V2.empty()){
            if (V1.empty()){
                cout<<V2.back();
                V2.pop_back();
            }
            else if (V2.empty()){
                cout<<V1.back();
                V1.pop_back();
            }
            else{
                if (V1.back()<V2.back()){
                    cout<<V1.back();
                    V1.pop_back();
                }
                else{
                    cout<<V2.back();
                    V2.pop_back();
                }
            }
        }
        cout<<endl;
    }
    return 0;
}