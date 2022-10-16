#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int a;
    cin>>a;
    int arr[a+5];
    for(int i=0;i<a;i++)cin>>arr[i];
    sort(arr,arr+a);
    for(int i=0;i<a-1;i++)if(arr[i+1]==arr[i]+1){cout<<"2"<<endl;return;}
    cout<<"1"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}