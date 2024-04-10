#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    int arr2[n+5];
    for(int i=0;i<n;i++){cin>>arr[i];arr2[i]=arr[i];}
    sort(arr2,arr2+n);
    int t=arr2[0];
    for(int i=0;i<n;i++){
        if(arr[i]%t!=0&&arr[i]!=arr2[i]){cout<<"NO"<<endl;return;}
    }
    cout<<"YES"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}