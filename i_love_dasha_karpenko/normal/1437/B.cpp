#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll cnt[] = {0,0};
        ll cur = (s[0]=='0');
        for(ll i = 0;i<s.length();++i){
            if (((s[i]-'0')==i%2)!=cur){
                ++cnt[cur];
                cur = ((s[i]-'0')==i%2);
            }
        }
        ++cnt[cur];
        cout<<min(cnt[0],cnt[1])<<endl;
    }
    return 0;

}