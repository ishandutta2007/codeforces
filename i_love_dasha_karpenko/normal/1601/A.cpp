#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int LOG = 32;
int po[LOG],cnt[LOG];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        for(int bit = 0;bit<LOG;++bit){
            if (val&po[bit])
                ++cnt[bit];
        }
    }
    int g = -1;

    for(int i = 0;i<LOG;++i){
        if (cnt[i]==0)
            continue;
        if (g==-1)
            g = cnt[i];
        g = __gcd(g,cnt[i]);
    }
    if (g==-1){
        for(int i = 1;i<=n;++i)
            cout<<i<<' ';
    }
    else
    for(int div = 1;div<=g;++div){
        if (g%div==0)
            cout<<div<<' ';
    }
    cout<<endl;
    for(int i = 0;i<LOG;++i)
        cnt[i] = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    po[0] = 1;
    for(int i = 1;i<LOG;++i)
        po[i] = po[i-1]<<1;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}