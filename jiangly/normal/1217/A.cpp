#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T,s,i,n;
    cin>>T;
    while(T--){
        cin>>s>>i>>n;
        cout<<max(0,n-max(-1,i+n-s>>1))<<endl;
    }
    return 0;
}