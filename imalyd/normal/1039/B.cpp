#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll l,r,n,k;
string Bad;
int ask(ll l,ll r){
    cout<<l<<" "<<r<<endl;
    cout.flush();
    cin>>Bad;
    if(Bad[0]=='B')exit(0);
    if(Bad[0]=='Y'){
        if(l==r)exit(0);
        return 1;
    }
    return 0;
}
int main(){
    srand(2109888);
    cin>>n>>k;l=1;r=n;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(ask(l,mid))r=mid;else l=mid+1;
        l=max(1ll,l-k);r=min(n,r+k);
        mid=l+rand()%(r-l+1);ask(mid,mid);
        l=max(1ll,l-k);r=min(n,r+k);
    }
    return 0;
}