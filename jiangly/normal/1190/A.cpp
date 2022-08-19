// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    int m;
    cin>>n>>m>>k;
    vector<ll> p(m);
    for(int i=0;i<m;++i){
        cin>>p[i];
        --p[i];
    }
    int ans=0;
    for(int i=0;i<m;){
        ll x=(p[i]-i)/k;
        int y=i;
        while(y<m&&(p[y]-i)/k==x){
            ++y;
        }
        ++ans;
        i=y;
    }
    cout<<ans<<endl;
    return 0;
}