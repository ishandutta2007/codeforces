// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,P,k;
    cin>>n>>P>>k;
    map<int,int>cnt;
    long long ans=0;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        int x=(1ll*a*a%P*a%P-k+P)*a%P;
        ans+=cnt[x];
        ++cnt[x];
    }
    cout<<ans<<endl;
    return 0;
}