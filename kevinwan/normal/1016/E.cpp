#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int mn=2e5+10;
const ll mod=1e9+7;
ll l[mn],r[mn],len[mn];
int n;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    double y,xl,xr;
    cin>>y>>xl>>xr,y=-y;
    cin>>n;
    for(int i=0;i<n;i++)cin>>l[i]>>r[i];
    len[0]=r[0]-l[0];
    for(int i=1;i<n;i++)len[i]=len[i-1]+r[i]-l[i];
    int q;
    cin>>q;
    while(q--){
        double a,b;
        cin>>a>>b;
        double k=b/(b+y),c=a*y/(b+y);
        double lv=k*xl+c,rv=k*xr+c;
        int lef=upper_bound(l,l+n,(ll)floor(lv))-l-1;
        int rig=upper_bound(l,l+n,(ll)floor(rv))-l-1;
        //if(n==200000)continue;
        double ans;
        if(lef==rig){
            if(lef==-1){
                ans=0;
            }
            else {
                lv = min(lv, (double)r[lef]), rv = min(rv, (double)r[lef]);
                ans = rv - lv;
            }
        }
        else{
            ans=(rig-1>=0?len[rig-1]:0)-(lef>=0?len[lef]:0);
            if(lef>=0)lv=min(lv,(double)r[lef]);
            if(rig>=0)rv=min(rv,(double)r[rig]);
            if(lef>=0)ans+=r[lef]-lv;
            if(rig>=0)ans+=rv-l[rig];
        }
        ans/=k;
        printf("%.6lf\n",ans);
    }
}