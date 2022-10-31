#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 5E5+7;
ll A[DIM],val[DIM];
ll solve(ll l,ll r,vector<ll> &tms){
    ll res = 0;
    if (tms.empty()){

        for(ll len = 1;len<=r-l+1;++len){
            res+=len*(r-l+2-len);
        }
        return res*A[l];
    }
    vector<ll> V1,V2;
    ll mid = tms.size()/2;
    //while(mid>0 && tms[mid]+1>r)--mid;
    for(ll i = 0;i<mid;++i){
        V1.push_back(tms[i]);
    }
    for(ll i = mid+1;i<tms.size();++i){
        V2.push_back(tms[i]);
    }
    ll tm = tms[mid];

    ll cur = 0,mx = 0;
    for(ll i = tm+1;i<=r;++i){
        if (A[i]==1)++cur;
        else cur = 0;
        mx = max(mx,cur);
        val[i-tm] = mx;
    }
    cur = mx = 0;
    for(ll i = tm;i>=l;--i){
        if (A[i]==1)++cur;
        else cur = 0;
        mx = max(mx,cur);
        ll pos = lower_bound(val+1,val+1+r-tm,mx)-val;
        --pos;
        res+=pos*mx;
    }
    cur = mx = 0;
    for(ll i = tm;i>=l;--i){
        if (A[i]==1)++cur;
        else cur = 0;
        mx = max(mx,cur);
        val[tm-i+1] = mx;
    }
    cur = mx = 0;
    for(ll i = tm+1;i<=r;++i){
        if (A[i]==1)++cur;
        else cur = 0;
        mx = max(mx,cur);
        ll pos = upper_bound(val+1,val+1+tm-l+1,mx)-val;
        --pos;
        res+=pos*mx;
    }
    if (tm==r)return res;
    return res+solve(l,tm,V1)+solve(tm+1,r,V2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vector<ll> tms;
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';

    }
    for(ll i = 1;i<n;++i){
        if (A[i]==0 || A[i+1]==0)tms.push_back(i);
    }
    cout<<solve(1,n,tms)<<endl;
    return 0;
}