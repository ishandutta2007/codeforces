#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    if(b<a*2)cout<<"-1 -1"<<endl;
    else cout<<a<<" "<<a*2<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}