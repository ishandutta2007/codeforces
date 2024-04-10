#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
ll a[mn],b[mn];
int n;
ll check(ll x){
    ll num=0;
    for(int i=0;i<n;i++){
        ll c=sqrt(max(a[i]-x,0LL)/3);
        c=max(c,-1LL);
        c=min(c,a[i]-1);
        while(c-1>=-1&&a[i]-(3*c*c+3*c+1)<x)c--;
        while(c+1<=a[i]-1&&a[i]-(3*(c+1)*(c+1)+3*(c+1)+1)>=x)c++;
        b[i]=c+1;
        num+=b[i];
    }
    return num;
}
int main(){
    ll k;
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    ll cur=-1LL<<62;
    for(ll i=1LL<<62;i;i>>=1){
        if(check(cur+i)>=k)cur+=i;
    }
    ll u=check(cur)-k;
    ll bes=LONG_LONG_MAX;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(b[i]==0)continue;
        ll sc=a[i]-(3*(b[i]-1)*(b[i]-1)+3*(b[i]-1)+1);
        if(sc<bes)bes=sc,v.clear(),v.push_back(i);
        else if(sc==bes)v.push_back(i);
    }
    for(int i=0;i<u;i++)b[v[i]]--;
    for(int i=0;i<n;i++)printf("%lld ",b[i]);
}