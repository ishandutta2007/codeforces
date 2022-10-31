#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 200000  +7;
const ll INF = 10E10;

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(q,t){
        ll n; cin>>n;
        string s; cin>>s;
        //s+=s;
        ll res = 0,cnt = 0;
        ll u = 0;
        while(u<s.length() && s[u]=='P')u++;
        for(ll i = u;i<s.length();i++){
            if (s[i]=='P')cnt++;
            else cnt = 0;
            res = max(res,cnt);
        }
        cout<<res<<endl;
    }
    return 0;
}