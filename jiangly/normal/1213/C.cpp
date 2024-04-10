#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int T;
LL n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m;
        n/=m;
        LL ans=0;
        for(int i=1;i<=10;++i){
            ans+=m*i%10;
        }
        ans*=n/10;
        for(int i=1;i<=n%10;++i){
            ans+=m*i%10;
        }
        cout<<ans<<endl;
    }
    return 0;
}