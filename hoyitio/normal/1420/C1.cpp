#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[666666];
int main(){
    ll n,i,j,t;
    cin>>t;

    while(t--){
        int q;
        cin>>n>>q;
        for(i=0;i<n;i++)
           cin>>a[i];
        int temp=0;
        ll sum=0;
        for(i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                j=i+1;
                while(j<n-1&&a[j]>a[j+1])j++;
                temp=a[j];
                sum+=a[i]-a[j];
                i=j;
            }
        }
       // cout<<sum<<" "<<temp<<endl;
        cout<<sum+a[n-1]<<endl;
    }


}