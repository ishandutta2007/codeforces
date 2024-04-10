#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    int t;
    for(int i=0;i<n;i++){cin>>t;arr[i]-=t;}
    int flag=0;
    if(arr[0]!=0)flag++;
    if(arr[0]>0){cout<<"NO"<<endl;return;}
    for(int i=1;i<n;i++){
        if(arr[i]>0){cout<<"NO"<<endl;return;}
        else if(arr[i]!=arr[i-1])flag++;
        if(arr[i]!=arr[i-1]&&arr[i]!=0&&arr[i-1]!=0){cout<<"NO"<<endl;return;}
    }
    if(flag<=2){cout<<"YES"<<endl;return;}
    else {cout<<"NO"<<endl;return;}
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}