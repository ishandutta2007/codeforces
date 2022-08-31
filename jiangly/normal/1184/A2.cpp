#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string y;
    cin>>n>>y;
    vector<int>can(n+1);
    for(int i=1;i<=n;++i){
        if(n%i==0){
            bool ok=true;
            for(int j=0;j<i;++j){
                int ans=0;
                for(int k=j;k<n;k+=i){
                    ans^=(y[k]-'0');
                }
                ok&=(ans==0);
            }
            can[i]=ok;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        ans+=can[__gcd(i,n)];
    }
    cout<<ans<<endl;
    return 0;
}