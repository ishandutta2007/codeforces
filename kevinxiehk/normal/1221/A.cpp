#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,cnt=0,tt,t;
    cin>>tt;
    for(int j=0;j<tt;j++){
        cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>t;
            if(t<=2048)cnt+=t;
        }
        if(cnt>=2048)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}