#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int  ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
const ll DIM = 1000000+7;
const ll INF = 10e14;
const ll MOD = 1000000007;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

ll n,tre[DIM*4],re[DIM*4],mx[DIM*4];
void update(ll t,ll tl,ll tr,ll l,ll r,ll delta){

    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        tre[t]+=delta;
        re[t]+=delta;
        mx[t]+=delta;
        return;
    }
    ll tm = (tl+tr)/2;
    tre[t*2+1]+=tre[t];
    tre[t*2+2]+=tre[t];
    re[t*2+1]+=tre[t];
    re[t*2+2]+=tre[t];
    mx[t*2+1]+=tre[t];
    mx[t*2+2]+=tre[t];
     tre[t] = 0;
    update(t*2+1,tl,tm,l,r,delta);
    update(t*2+2,tm+1,tr,l,r,delta);

    re[t] = min(re[t*2+1],re[t*2+2]);
    mx[t] = max(mx[t*2+1],mx[t*2+2]);


}
string S="";
void del(ll pos,char ch){
    if (ch=='(')update(0,0,n-1,pos,n-1,-1);
    if (ch==')')update(0,0,n-1,pos,n-1,1);

}
void add(ll pos,char ch){
    if (ch=='(')update(0,0,n-1,pos,n-1,1);
    if (ch==')')update(0,0,n-1,pos,n-1,-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(ll i = 0;i<n;i++)S+=' ';
    string s; cin>>s;
    ll pos = 0;
    ll cnt1 = 0,cnt2 = 0,lastr = 0;
    for(ll i = 0;i<s.length();i++){
        char ch = s[i];
        if (ch=='L'){
            if (pos!=0)
            pos--;
            cout<<lastr<<' ';
            continue;
        }
        else if (ch=='R'){
            if (pos!=(n-1))
            pos++;
            cout<<lastr<<' ';
            continue;
        }
        del(pos,S[pos]);
        add(pos,ch);

        if (ch=='(')cnt1++;
        if (ch==')')cnt2++;
        if (S[pos]=='(')cnt1--;
        if (S[pos]==')')cnt2--;
        S[pos] = ch;
        ll p = re[0];
        //cout<<p<<' ';
        if (p!=0 || cnt1!=cnt2)lastr = -1;
        else lastr = mx[0];
        cout<<lastr<<' ';

        //cout<<re[0]<<endl;
    }
    return 0;
}