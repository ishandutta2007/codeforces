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

ll t,vis[40];
string s;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    forn(query,t){
        cin>>s;
        memset(vis,0,sizeof(vis));
        ll cnt = 0,symb = -1;
        for(ll i = 0;i<s.length();i++){
            if (i==0 || s[i-1]!=s[i]){
                if(symb!=-1 && cnt%2!=0)vis[symb] = 1;
                symb = s[i]-'a';
                cnt = 1;
            }
            else cnt++;
        }
        if (cnt%2!=0)vis[symb] = 1;
        string res = "";
        for(ll i = 0;i<=ll('z'-'a');i++){
            if (vis[i]==1){
                res+='a'+i;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}