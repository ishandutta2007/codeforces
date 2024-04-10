#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[2][n+5];
    arr[0][0]=0;
    arr[1][0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[0][i]>>arr[1][i];
    }
    int lst=-1;
    int ans=0;
    for(int i=1;i<=n;i++){
        int t=max(arr[0][i-1],arr[1][i-1]);
        int tt=min(arr[0][i],arr[1][i]);
        int ttt=tt-t+1;
        if(t==lst)ttt--;
        lst=tt;
        int zro=0;
        ans+=max(zro,ttt);
        //cout<<i<<"  "<<ans<<"  "<<ttt<<endl;
    }
    cout<<ans<<endl;
    return 0;
}