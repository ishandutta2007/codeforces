#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E6+7;
const ll INF = 1e9;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
char buf[DIM];
string s;
const ll base =31;
const ll MOD = 1e9+123;
ll gi(char ch){
    return ch-'a'+1;
}
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
upp pref[DIM],suf[DIM],po[DIM];
upp getpref(ll l,ll r){
    l--;
    if (l<0)return pref[r];
    upp h1 = pref[l];
    upp h2 = pref[r];
    h1.fi*=po[r-l].fi;
    h1.sc = (h1.sc*po[r-l].sc)%MOD;
    h2.fi-=h1.fi;
    h2.sc-=h1.sc;
    if (h2.sc<0)h2.sc+=MOD;
    return h2;
}
upp getsuf(ll l,ll r){
    l++;
    upp h1 = suf[l];
    upp h2 = suf[r];
    h1.fi*=po[l-r].fi;
    h1.sc = (h1.sc*po[l-r].sc)%MOD;
    h2.fi-=h1.fi;
    h2.sc-=h1.sc;
    if (h2.sc<0)h2.sc+=MOD;
    return h2;
}
int main(){
    po[0] = {1,1};
    forn(i,DIM-1){
        po[i].fi = po[i-1].fi*base;
        po[i].sc = (po[i-1].sc*base)%MOD;
    }
    ll t;
    scanf("%lld",&t);
    while(t--){
        scanf("%s",&buf);
        s = buf;
        ll n = s.length();
        pref[0] = {gi(s[0]),gi(s[0])};
        for(ll i = 1;i<n;++i){
            pref[i].fi = pref[i-1].fi*base+gi(s[i]);
            pref[i].sc = (pref[i-1].sc*base+gi(s[i]))%MOD;
        }
        suf[n] = {0,0};
        for(ll i = n-1;i>=0;--i){
            suf[i].fi = suf[i+1].fi*base+gi(s[i]);
            suf[i].sc = (suf[i+1].sc*base+gi(s[i]))%MOD;
        }
        ll p1 = 0,p2 = n-1;
        while(p1<p2 && s[p1]==s[p2]){
            p1++;
            p2--;
        }
        ll res = 0;
        pp st = {-1,-1};
        ll flag = 0;
        for(ll i = p1;i<=p2;i++){
            ll l = 0,r = min(i-p1,p2-i);
            while(l!=r){
                ll tm = (l+r+1)/2;
                if (getpref(i,i+tm)==getsuf(i,i-tm))l = tm;
                else r = tm-1;
            }
            if ((i-l==p1 || l+i==p2) && res<l*2+1){
                res = l*2+1;
                st = {i,l};
                flag = 0;
            }
            //res = max(res,1+l*2);
            l = 0; r = min(i-p1,p2-i-1);

            if (i==p2 || s[i]!=s[i+1])continue;
            while(l!=r){
                ll tm = (l+r+1)/2;
                if (getsuf(i,i-tm)==getpref(i+1,i+1+tm))l = tm;
                else r = tm-1;
            }
            if ((i-l==p1 || i+l+1==p2) && res<l*2+2){
                res = l*2+2;
                flag = 1;
                st = {i,l};
            }
        }
        for(ll i = 0;i<p1;i++)printf("%c",s[i]);
        ll ff = 0;
        if (st.fi!=-1 && st.fi-st.sc==p1){
            for(ll i = p1;i<=st.fi+st.sc+flag;++i)printf("%c",s[i]);
            ff = 1;
        }
        if (ff==0 && st.fi!=-1 && st.fi+st.sc+flag==p2){
            for(ll i = st.fi-st.sc;i<=p2;++i)printf("%c",s[i]);
        }
        for(ll i = p2+1;i<n;++i)printf("%c",s[i]);

        printf("\n");
    }
    return 0;
}
// a[i]-b[i]>b[j]-a[j]