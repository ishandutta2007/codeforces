#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
void solve(){
    string s;
    int x;
    cin>>s>>x;
    int n=s.length();
    int ans[n+5];
    for(int i=0;i<n;i++)ans[i]=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(i>=x)ans[i-x]=0;
            if(i+x<n)ans[i+x]=0;
        }
    }
    for(int i=0;i<n;i++)ans[i]=abs(ans[i]);
    bool ok;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ok=false;
            if(i>=x)if(ans[i-x])ok=true;
            if(i+x<n)if(ans[i+x])ok=true;
            if(!ok){cout<<"-1"<<endl;return;}
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i];
    cout<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    cin>>t;
    
    while(t--)solve();
    return 0;
}