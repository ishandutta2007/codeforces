#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
    int n;
    int t;
    cin>>n;
    int psum[n+5];
    psum[0]=0;
    int even=0;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t<0){
            psum[i]=psum[i-1]+1;
        }
        else psum[i]=psum[i-1];
        if(psum[i]%2==0)even++;
    }
    int pos=0,neg=0;
    for(int i=0;i<n;i++){
        if(psum[i]%2==0&&i!=0)even--;
        int t=n-i;
        if(psum[i]%2==0){
            pos+=even;
            neg+=(t-even);
        }
        else{
            pos+=(t-even);
            neg+=even;
        }
    }
    cout<<neg<<" "<<pos<<endl;
    return 0;
}