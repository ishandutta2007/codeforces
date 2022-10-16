#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    if(b<=a){cout<<"YES"<<endl;return;}
    if(a==2&&b==3){cout<<"YES"<<endl;return;}
    if(a<=3)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}