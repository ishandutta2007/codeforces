#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;cin>>s;
    int pre[n+5];
    pre[0]=0;
    bool poss=true;
    for(int i=0;i<k;i++){
        char c='.';
        for(int j=i;j<n;j+=k){
            if(s[j]!='?'){
                if(c=='.')c=s[j];
                else if(c!=s[j])poss=false;
            }
        }
        for(int j=i;j<n;j+=k){
            s[j]=c;
        }
    }
    int cnt1=0,cnt0=0;
    for(int i=0;i<k;i++){
        if(s[i]=='0')cnt0++;
        if(s[i]=='1')cnt1++;
    }
    if(cnt0>k/2||cnt1>k/2)poss=false;
    if(poss)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //cout<<s<<endl;
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