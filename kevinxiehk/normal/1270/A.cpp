#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int amax=0;
    int t;
    for(int i=0;i<b;i++){
        cin>>t;
        if(t==a)cout<<"YES"<<endl;
    }
    for(int i=0;i<c;i++){
        cin>>t;
        if(t==a)cout<<"NO"<<endl;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}