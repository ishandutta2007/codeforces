#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        ll xmx = 0,xmi = 0,ymi = 0,ymx = 0;
        for(char to:s){
            if (to=='U')ymx++;
            if (to=='D')ymi--;
            if (to=='L')xmi--;
            if (to=='R')xmx++;
        }
        if (xmi<=x && x<=xmx && ymi<=y && y<=ymx)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}