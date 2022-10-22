#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll Mod1=1e18+3;
const ll Mod2=1e18+9;
int T,n,m; pii a[510000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            ll x,s=0;
            ll res1=0,res2=0;
            for (int j=1;j<=m;j++){
                cin>>x; s+=x;
                res1=(res1+s)%Mod1;
                res2=(res1+s)%Mod2;
            }
            a[i]=pii(res1,res2);
        }
        pii v=(a[1]==a[2]?a[1]:(a[1]==a[3]?a[1]:a[2]));
        int pos=0;
        for (int i=1;i<=n;i++)
            if (a[i]!=v) pos=i;
        cout<<pos<<' '<<(v.first-a[pos].first+Mod1)%Mod1<<'\n';
    }
    return 0;
}