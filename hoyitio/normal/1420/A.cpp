#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int a[666666];
int main(){
    ll n,i,j,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=1;i<n;i++){
            if(a[i]>=a[i-1])break;
        }
        if(i==n)cout<<"NO\n";
        else cout<<"YES\n";
    }


}