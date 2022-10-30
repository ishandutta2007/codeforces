#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 200000+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

ll Check(char ch,const string s,ll pos){
    ll pref = 0,cnt = 0,po = 0;
    for(ll i = pos;i<s.length();i++){
        if (s[i]==ch){
            return i;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,k; cin>>n>>k;
        string s; cin>>s;
        vector<pp> ans;
        k--;
        char ch = '(';
        ll i = 0;
        for(i = 0;i<s.length();i++){
            if (k==0)break;
            ll j=  Check(ch,s,i);
            if (j!=i)ans.pb({i,j});
            swap(s[i],s[j]);
            if (ch=='(')ch = ')';
            else{
                k--;
                ch = '(';
            }
        }
        ll cnt = (s.length()-i)/2;
        //cout<<cnt<<endl;
        for (i = i;i<s.length();i++){
            if (cnt<=0)ch = ')';
            else ch = '(';
            cnt--;
            ll j = Check(ch,s,i);
            if (j!=i)ans.pb({i,j});
            swap(s[i],s[j]);
        }
        //cout<<s<<endl;
        cout<<ans.size()<<endl;
        for(ll j = 0;j<ans.size();j++){
            pp to = ans[j];
            cout<<to.fi+1<<' '<<to.sc+1<<endl;
        }
    }
    return 0;
}