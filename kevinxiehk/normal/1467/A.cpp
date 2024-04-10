#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
using namespace std;
void solve(){
    int n;cin>>n;
    if(n==1)cout<<"9\n";
    else if(n==2)cout<<"98\n";
    else{
        cout<<"989";
        for(int i=4;i<=n;i++){
            cout<<(i+6)%10;
        }cout<<"\n";
    }
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}