#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
struct idk{
    int cnt,wei;
};
void solve(){
    int a,b;
    cin>>a>>b;
    idk x,y;
    cin>>x.cnt>>y.cnt>>x.wei>>y.wei; 
    if(x.wei>y.wei){
        swap(x,y);
    }
    int ans=0,tans=0,tx,ty,tb;
    for(int i=0;i<=x.cnt;i++){
        int t=x.wei*i;
        tans=i;
        if(t>a)continue;
        tx=x.cnt-i;
        ty=y.cnt-(a-t)/y.wei;
        tans+=(a-t)/y.wei;
        tans+=min(tx,b/x.wei);
        tb=b-min(tx,b/x.wei)*x.wei;
        tans+=min(ty,tb/y.wei);
        ans=max(ans,tans);
    }
    cout<<ans<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    cin>>t;
    
    while(t--)solve();
    return 0;
}