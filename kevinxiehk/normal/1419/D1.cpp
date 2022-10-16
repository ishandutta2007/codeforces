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
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n<=2){
        cout<<"0"<<endl;
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    int ans[n+5];
    for(int i=0;i<n;i++)ans[i]=-1;
    sort(arr,arr+n);
    for(int i=0;i<(n-1)/2;i++){
        ans[i*2+1]=arr[i];
        arr[i]=-1;
    }
    int now=(n-1)/2;
    int cnt=0;
    while(now<n&&arr[now]<=ans[1])now++;
    if(now<n){ans[0]=arr[now];
    arr[now]=-1;
    now++;}
    for(int i=2;i<n;i++){
        if(i%2==1)continue;
        while(now<n&&arr[now]<=ans[i-1])now++;
        if(now==n)break;
        ans[i]=arr[now];
        arr[now]=-1;
        now++;cnt++;
    }
    queue<int>dump;
    for(int i=0;i<n;i++){
        if(arr[i]!=-1)dump.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(ans[i]==-1){
            ans[i]=dump.front();
            dump.pop();
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    //cin>>t;
    
    while(t--)solve();
    return 0;
}