#include<bits/stdc++.h>
using namespace std;
void solve(){
     int n;cin>>n;
     pair<int,int>arr[n+5];
     for(int i=0;i<n;i++)cin>>arr[i].first,arr[i].second=i;
     sort(arr,arr+n);
     int tt=0;
     while(tt<n&&(arr[tt+1].first==arr[tt].first||(tt>0&&arr[tt].first==arr[tt-1].first)))tt++;
     if(tt==n)cout<<"-1"<<endl;
     else cout<<arr[tt].second+1<<endl;
     return;
}
int main(){
     int t;cin>>t;
     while(t--)solve();
}