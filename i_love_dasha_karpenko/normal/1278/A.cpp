#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100+7;
const ll INF = 10E16;
map<char,ll> M,M1;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        M.clear();
        M1.clear();
        string p;
        string h;
        cin>>p>>h;
        if (p.length()>h.length()){
            cout<<"NO\n";
            continue;
        }
        ll flag =0;

        for(ll i = 0;i<p.length();i++){
            M1[p[i]]++;
        }
        ll cnt = 0;
        for(ll i = 0;i<p.length();i++){
            M[h[i]]++;
            if (M1.count(h[i])==1 )if (M1[h[i]]!=0 && M1[h[i]]==M[h[i]])cnt++;
        }
        if (cnt==M1.size())flag = 1;
        for(ll i = p.length();i<h.length();i++){
            M[h[i-p.length()]]--;
            //cout<<h[i-p.length()]<<endl;
            if (M1.count(h[i-p.length()])==1)
                if (  M[h[i-p.length()]]+1==M1[h[i-p.length()]])cnt--;
            M[h[i]]++;
            if (M1.count(h[i])==1 )if (M1[h[i]]!=0 && M1[h[i]]==M[h[i]])cnt++;
            if (cnt==M1.size())
                flag = 1;
        }
        if (flag==1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

// 1 2 3
//