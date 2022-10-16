#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=c+1;
    ans-=max(0,c-a);
    ans-=max(0,c-b);
    cout<<ans<<endl;
    return  0;
}