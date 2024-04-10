#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int a[666666];
int main(){
    ll n,i,j,t;
    cin>>t;

    while(t--){
        cin>>n;
        ll tong[33]={0};
        for(i=0;i<n;i++){
            int x;
            cin>>x;
            int cnt=0;
            while(x/=2)cnt++;
            tong[cnt]++;
        }
        ll res=0;
        for(i=0;i<32;i++){
            res+=tong[i]*(tong[i]-1)/2;
        }
        cout<<res<<endl;
    }


}