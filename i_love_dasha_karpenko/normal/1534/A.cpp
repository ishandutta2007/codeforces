//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
void solve(){
    ll n,m;
    cin>>n>>m;
    ll rpos = -1,wpos = -1,flag = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            char ch;
            cin>>ch;
            if (ch=='R')
                if (rpos!=-1 && rpos!=(i+j)%2)
                    flag = 1;
                else rpos = (i+j)%2;
            if (ch=='W')
                if (wpos!=-1 && wpos!=(i+j)%2)
                    flag = 1;
                else wpos = (i+j)%2;
        }
    }
    if (rpos==-1 && wpos==-1)
        rpos = 0,wpos = 1;
    if (rpos==-1 || wpos==-1)
        if (rpos!=-1)
            wpos = 1-rpos;
        else rpos = 1-wpos;
    if (rpos==wpos || flag)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=m;++j){
                if ((i+j)%2==rpos)
                    cout<<'R';
                else cout<<'W';
            }
            cout<<endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}