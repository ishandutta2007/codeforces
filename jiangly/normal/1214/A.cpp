#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,d,e;
    cin>>n>>d>>e;
    e*=5;
    int ans=n;
    for(int i=0;i<=e&&i*d<=n;++i){
        ans=min(ans,(n-i*d)%e);
    }
    cout<<ans<<endl;
    return 0;
}