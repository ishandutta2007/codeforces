#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
using namespace std;
void solve(){
    string s;int n;
    cin>>s;n=s.length();
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='A')continue;
        if(s[i]==s[i+1]){
            s[i+1]='A';
            ans++;
        }
        if(i<n-2&&s[i]==s[i+2]){
            ans++;
            s[i+2]='A';
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}