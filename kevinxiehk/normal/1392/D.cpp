#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
int div3(int a){
    if(a<=2)return 0;
    return (a)/3;
}
void solve(){
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    bool allsame=true;
    for(int i=1;i<n;i++)if(s[i]!=s[i-1]){allsame=false;}
    if(allsame){cout<<div3(n+2)<<endl;return;}
    bool nev=true;
    int now=1,t;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            if(nev){
                t=now;
                nev=false;
            }
            else ans+=div3(now);
            now=1;
        }
        else now++;
    }
    if(s[0]==s[n-1])ans+=div3(now+t);
    else ans+=(div3(now)+div3(t));
    cout<<ans<<endl;
}
main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}