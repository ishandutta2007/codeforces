#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 10E4+7;
const ll INF = 10E17+7;
const ld MAXN = 1000007.0;
const ld eps = 0.000000000000001;
void get(ll l,ll r,vector<string> &V){
    cout<<"? "<<l<<' '<<r<<endl;
    forn(i,(r-l+1)*(r-l+2)/2){
        string s; cin>>s;
        V.pb(s);
    }
}
ll cnt[30],oldcnt[30];
bool mc(string &a,string &b){
    return a.length()<b.length();
}
int main()
{
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;

    vector<string> a;
    get(1,n,a);
    if (n==1){
        cout<<"! "<<a[0]<<endl;
        return 0;
    }
    vector<string> b;
    get(2,n,b);
    map<string,ll> M;

    for(ll i = 0;i<b.size();i++){
        sort(b[i].begin(),b[i].end());
        M[b[i]]++;
    }
    vector<string> V;
    for(ll i = 0;i<a.size();i++){
        sort(a[i].begin(),a[i].end());
        if (M.count(a[i])==0)V.pb(a[i]);
        else{
            M[a[i]]--;
            if (M[a[i]]==0)M.erase(a[i]);
        }
    }
    sort(V.begin(),V.end(),mc);

    //cout<<V.size()<<endl;
    string res = "";
    for(string to:V){
        for(char ch:to)cnt[ch-'a']++;
        for(ll i = 0;i<30;i++){
            if (cnt[i]!=oldcnt[i])
                res+='a'+char(i);
            oldcnt[i] = cnt[i];
            cnt[i] = 0;
        }
        //cout<<res<<' '<<to<<endl;

    }
    cout<<"! "<<res<<endl;

    return 0;
}

// 1 2 3
//