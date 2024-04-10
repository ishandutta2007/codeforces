#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    reverse(arr,arr+n);
    int cnt=0;
    int nowgrp=0,minneed=0;
    for(int i=0;i<n;i++){
        minneed=k/arr[i]+(k%arr[i]!=0);
        nowgrp++;
        if(minneed<=nowgrp){
            cnt++;
            minneed=0;
            nowgrp=0;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}