#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll k[4],bac[4];
int rep(ll x){
    cout<<x<<endl;
    int a;
    cin>>a;
    if(a<=0)exit(0);
    return a;
}
int main(){
#ifdef LOCAL_PROJECT
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    //cin.tie(0);
    //cin.sync_with_stdio(0);
#endif
    ll a[4];
    cin>>a[1]>>a[2]>>a[3];
    cout<<"First"<<endl;
    ll big=1e11,big2=1e10;
    k[2]=rep(big2);
    a[k[2]]+=big2;
    k[3]=rep(big);
    a[k[3]]+=big;
    k[1]=k[2]^k[3];
    for(int i=1;i<=3;i++)bac[k[i]]=i;
    ll ad=2*a[k[3]]-a[k[2]]-a[k[1]];
    int p=rep(ad);
    a[p]+=ad;
    if(bac[p]==1){
        rep(a[k[1]]-a[k[3]]);
    }
    else{
        rep(a[k[2]]-a[k[3]]);
    }
    return 1;
}