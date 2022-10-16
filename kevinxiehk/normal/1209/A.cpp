#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int cnt=0,t=0;
    for(int i=0;i<n;i++){
        if(arr[i]==-1)continue;
        t=arr[i];
        cnt++;
        for(int j=i;j<n;j++){
            if(arr[j]%t==0)arr[j]=-1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}