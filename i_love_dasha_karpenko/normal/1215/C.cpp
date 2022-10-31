#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 4*10E4 +7;
const ll INF = 10E17;

ll n,cnt[27];
ll gi(char ch){
    return ch-'a'+1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(char ch:s){
        cnt[gi(ch)]++;
    }
    for(char ch:t){
        cnt[gi(ch)]++;
    }
    forn(i,26){
        if (cnt[i]%2!=0){
            cout<<"-1\n";
            return 0;
        }
    }
    queue<ll> Da,Db;

    for(ll i = 0;i<n;i++){
        if (s[i]==t[i])continue;
        if (s[i]=='a')Da.push(i);
        else Db.push(i);
    }
    vector<pp> ans;
    for(ll i = 0;i<n;i++){
        if (s[i]==t[i])continue;
        if (s[i]=='a')Da.pop();
        else Db.pop();
        if (s[i]=='a' && Da.empty()){
            ans.pb({i,i});
            swap(s[i],t[i]);
        }
        if (s[i]=='b' && Db.empty()){
            ans.pb({i,i});
            swap(s[i],t[i]);
        }
        if (s[i]=='a'){
            ll p = Da.front();
            Da.pop();
            swap(s[i],t[p]);
            ans.pb({i,p});
        }
        else{
            ll p = Db.front();
            Db.pop();
            swap(s[i],t[p]);
            ans.pb({i,p});
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.back().fi+1<<' '<<ans.back().sc+1<<endl;
        ans.pop_back();
    }
    return 0;
}