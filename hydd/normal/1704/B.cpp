#include<bits/stdc++.h>
using namespace std;
int T,n,x,a[210000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T;
    while (T--){
        cin>>n>>x;
        for (int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for (int i=1,j=1;i<=n;i=j){
            int l=a[i]-x,r=a[i]+x;
            while (j<=n&&l<=r) l=max(a[j+1]-x,l),r=min(a[j+1]+x,r),j++;
            ans++;
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}