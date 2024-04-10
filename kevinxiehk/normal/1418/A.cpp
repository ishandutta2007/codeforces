#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    x--;
    int t=k;
    k*=(y+1);
    k--;
    t+=k/(x);   
    if(k%(x)!=0)t++;
    cout<<t<<endl;
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