#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        arr[i]=(int)(c-'0'-1);
    }
    map<int,int>cnt;
    int ans=0,now=0;
    cnt[0]++;
    for(int i=0;i<n;i++){
        now+=arr[i];
        ans+=cnt[now];
        cnt[now]++;
        //cout<<i<<" "<<now<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return;
}
main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}