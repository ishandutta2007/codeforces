#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t,a,b,X;
int main(){
    cin>>t>>n>>a>>b>>k;
    a = min(a,t);
    b=min(b,t);
    X=a*((n+1)/2)+b*(n/2);
    ll u=t,d=0ll;
    ll m;
    while(abs(u-d)>1){
        m=(u+d)/2;
        X=min(a,m)*((n+1)/2)+min(b,m)*(n/2);
        if(X<k*m){
            u=m;
        }
        else d=m;
    }
    m=max(0ll,min(u+1,t));
    X=min(a,m)*((n+1)/2)+min(b,m)*(n/2);
    if(X>=k*m){
        cout<<m;
        return 0;
    }
    m=max(min(u,t),0ll);
    X=min(a,m)*((n+1)/2)+min(b,m)*(n/2);
    if(X>=k*m){
        cout<<m;
        return 0;
    }
    m=max(min(u-1,t),0ll);
    X=min(a,m)*((n+1)/2)+min(b,m)*(n/2);
    if(X>=k*m){
        cout<<m;
        return 0;
    }
    m=max(min(u-2,t),0ll);
    X=min(a,m)*((n+1)/2)+min(b,m)*(n/2);
    if(X>=k*m){
        cout<<m;
        return 0;
    }
    cout<<"0";
}