#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
//template<typename TN>
//typedef tree<TN,null_type,less<TN>,rb_tree_tag,tree_order_statistics_node_update> super_set<TN>;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 2*10E4 +7;
const ll INF = 10E17;
const ll MAXN = 10E5;
struct node{
    ll a,b,c,d;
};
const bool operator<(const node &a,const node &b){
    if (a.a==b.a){
        if (a.b==b.b){
            if (a.c==b.c)return a.d<b.d;
            return a.c<b.c;
        }
        return a.b<b.b;
    }
    return a.a<b.a;
}
map<node,ll> M;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        M.clear();
        node st = {0,0,0,0};
        M[st] = 0;
        ll res = INF;
        pp ans;
        for(ll i = 0;i<s.length();i++){
            if (s[i]=='L')st.a++;
            else if (s[i]=='R')st.b++;
            else if (s[i]=='U')st.c++;
            else st.d++;
            if (st.a>=st.b){
                st.a-=st.b;
                st.b = 0;
            }
            if (st.b>=st.a){
                st.b-=st.a;
                st.a = 0;
            }
            if (st.c>=st.d){
                st.c-=st.d;
                st.d = 0;
            }
            if (st.d>=st.c){
                st.d-=st.c;
                st.c = 0;
            }
            if (M.count(st)==0)M[st] = i+1;
            else{
                if (i+1-M[st]+1<res){
                    res = i-M[st]+1;
                    ans.fi = 1+M[st];
                    ans.sc = i+1;
                }
                M[st] = i+1;
            }

        }
        if (res==INF)cout<<"-1\n";
        else cout<<ans.fi<<' '<<ans.sc<<endl;
    }
    return 0;
}