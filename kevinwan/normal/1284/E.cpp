#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef long double ld;
ll mod=1e9+7;
const ld pi=acos(-1.L);
const ld eps=0;
const int mn=2e5+10;
ll x[mn],y[mn];
ll xx,yy;
ll hail(ll n){
    return n*(n-1)*(n-2)/6;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld%lld",x+i,y+i);
    ll ans=0;
    for(int i=0;i<n;i++){
        vector<ld>ang;
        for(int j=0;j<n;j++)if(i!=j)ang.push_back(atan2(0.L+y[j]-y[i],0.L+x[j]-x[i]));
        sort(ang.begin(),ang.end());
        for(int j=0;j<n-1;j++)ang.push_back(ang[j]+2*pi);
        ans+=1LL*(n-1)*(n-2)*(n-3)*(n-4)/24;
        for(int j=0,k=0;j<n-1;j++){
            while(ang[k]<ang[j]+pi+eps)k++;
            ans-=hail(k-j-1);
        }
    }
    //ans/=4;
    cout<<ans;
}