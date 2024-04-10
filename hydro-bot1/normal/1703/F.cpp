// Hydro submission #62d2bcfeb36e4a12382b18fc@1657978111951
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void fun(){
    ll n;
    cin>>n;
    ll ans=0;
    ll a[200010];
    vector<int>ve;
    int id=0;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x<i){
            auto it=lower_bound(ve.begin(),ve.end(),x);
            ans+=it-ve.begin();
            ve.push_back(i);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        fun();
    }
    return 0;
}