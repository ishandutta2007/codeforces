#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
void solve(){
    int a;
    cin>>a;
    int arr[a+5];
    int sum=0,xorsum=0;
    for(int i=0;i<a;i++){cin>>arr[i];sum+=arr[i];xorsum^=arr[i];}
    arr[a]=100000000000000000;
    sum+=arr[a];
    if(sum%2){
        arr[a]--;
        sum--;
    }
    sum/=2;
    xorsum^=arr[a];
    int t=xorsum-sum;
    cout<<"3"<<endl;
    cout<<arr[a]<<" "<<t<<" "<<t<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}