#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    int x=b;
    a-=x;
    if(a<0)cout<<-a<<endl;
    else cout<<a%2<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}