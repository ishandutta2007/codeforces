#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    int tot[n+5];
    for(int i=0;i<=n;i++)tot[i]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        tot[arr[i]]++;
    }
    int tmp[n+5];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++)tmp[j]=0;
        tot[arr[i]]--;
        int tans=0;
        for(int j=i+1;j<=n;j++){
            //cout<<i<<" "<<j<<" "<<tans<<endl;
            if(arr[j]==arr[i]){
                ans+=(tans-tmp[arr[j]]);
            }
            tans-=tmp[arr[j]]*(tot[arr[j]]-tmp[arr[j]]);
            tmp[arr[j]]++;
            tans+=tmp[arr[j]]*(tot[arr[j]]-tmp[arr[j]]);
        }
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