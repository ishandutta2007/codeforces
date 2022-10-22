#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[110000],b[110000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=m;i++) cin>>a[i];
        sort(a+1,a+m+1); b[1]=n+a[1]-a[m]-1;
        for (int i=2;i<=m;i++) b[i]=a[i]-a[i-1]-1;
        sort(b+1,b+m+1,greater<int>());
        int ans=0,tmp=0;
        for (int i=1;i<=m;i++){
            if (b[i]-tmp<1) break;
            ans+=max(1,b[i]-tmp-1); tmp+=4;
        }
        cout<<n-ans<<'\n';
    }
    return 0;
}