#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,w;
ll a[N],g,st,ans;
char s[N];
int main(){
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='L'){
            if(st<a[i]){
                ll x=a[i]-st;st+=x;
                if(w)ans+=3*x;else ans+=5*x;
            }
            st-=a[i],ans+=a[i];
        }else{
            ll x=5;
            if(s[i]=='W')x=3,w=1;
            else g+=a[i]<<1;
            st+=a[i],ans+=x*a[i];
        }
        g=min(g,st);
    }
    cout<<ans-(g<<1)-(st-g);
    return 0;
}