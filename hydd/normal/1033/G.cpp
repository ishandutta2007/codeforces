#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t[110000]; ll ans,ans1,ans2,v[110000];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int c=2;c<=m+m;c++){//a+b=c
        for (int i=1;i<=n;i++) t[i]=v[i]%c;
        sort(t+1,t+n+1);

        t[0]=0; t[n+1]=c-1; int now=1;
        for (int i=n+1;i>=1;i--,now^=1){
            int l=t[i-1]+1,r=min(t[i],m);
            if (now) l=max(l,t[n]/2+1); else l=max(l,t[n-1]/2+1);
            l=max(l,c-r); r=min(r,c-l); if (l>r) continue;
            if (now) ans2+=r-l+1; else ans1+=r-l+1;
        }
    }
    ans=(1ll*m*m-ans1-ans2)/2;
    cout<<ans<<' '<<ans<<' '<<ans1<<' '<<ans2<<'\n';
    return 0;
}