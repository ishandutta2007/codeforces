#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    int dist[n+5];
    int last[n+5];
    for(int i=0;i<=n;i++){
        dist[i]=n+10;
        last[i]=-1;
    }
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        if(last[arr[i]]==-1)last[arr[i]]=i;
        else {dist[arr[i]]=min(dist[arr[i]],i-last[arr[i]]);last[arr[i]]=i;}
    }
    sort(dist+1,dist+1+n);
    if(dist[1]>=n)cout<<"-1"<<endl;
    else cout<<dist[1]+1<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}