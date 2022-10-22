#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=100009;
ll w,g,wg;
bool bw;
int n;
ll a[M],ans;
char s[M];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>(s+1);
    for(int i=1;i<=n;++i){
        if(s[i]=='W'){
            bw=1;
            w+=a[i];
            ans+=a[i]*3;
        }
        if(s[i]=='G'){
            ans+=a[i]*5;
            ll x=min(w-wg,a[i]);
            wg+=x;
            g+=a[i]-x;
        }
        if(s[i]=='L'){
            ans+=a[i];
            ll x;
            x=min(a[i],w);
            a[i]-=x;
            w-=x;
            x=max(wg-w,0ll);
            g+=x;
            wg-=x;

            x=min(a[i],g);
            a[i]-=x;
            g-=x;
            x=min(a[i],wg);
            a[i]-=x;
            wg-=x;
            
            if(a[i]){
                if(bw){
                    ans+=a[i]*3;
                }
                else ans+=a[i]*5;
            }
        }
    }
    ll x;
    x=min(w,wg);
    ans-=x*4;
    w-=x;
    wg-=x;
    ans-=w;
    ans-=g*2;
    ans-=wg*2;
    cout<<ans<<endl;
    return 0;
}
/*
1
2
codeforces
technocup

*/