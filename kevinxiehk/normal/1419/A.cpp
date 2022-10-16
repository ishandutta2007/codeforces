#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    bool yeet=false;
    char c;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(i%2==n%2){
            if((c-'0')%2==n%2)yeet=true;
        }
    }
    if(yeet)cout<<((n+1)%2)+1<<endl;
    else cout<<(n%2)+1<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    cin>>t;
    
    while(t--)solve();
    return 0;
}