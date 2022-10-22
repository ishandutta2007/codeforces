#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
const int mn=2e5+10;
int n;
ld a[mn],p[mn];
ld val(ld x){
    ld sm=0,lar=0,ans=0;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i]-x;
        sm=min(sm,p[i]);
        lar=max(lar,p[i]);
        ans=max(ans,max(abs(p[i]-sm),abs(p[i]-lar)));
    }
    return ans;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ld l=-20000,r=20000;
    while(r-l>1e-12){
        ld a=(2*l+r)/3,b=(2*r+l)/3;
        if(val(a)<val(b))r=b;
        else l=a;
    }
    printf("%.100Lf",val((l+r)/2));
}