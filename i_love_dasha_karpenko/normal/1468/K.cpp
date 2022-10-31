//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll vis[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll flag = 0;
        pair<ll,ll> pos = {0,0};
        for(ll obs = 0;obs<s.length();++obs){
            if (s[obs]=='L')pos.first--;
            if (s[obs]=='R')pos.first++;
            if (s[obs]=='U')pos.second++;
            if (s[obs]=='D')pos.second--;
            pair<ll,ll> cur = {0,0};
            for(ll i = 0;i<s.length();++i){
                pair<ll,ll> prev = cur;
                if (s[i]=='L')cur.first--;
                if (s[i]=='R')cur.first++;
                if (s[i]=='U')cur.second++;
                if (s[i]=='D')cur.second--;
                if (cur==pos)cur = prev;
            }
            if (cur==pair<ll,ll>{0,0}){
                cout<<pos.first<<' '<<pos.second<<endl;
                flag = 1;
                break;
            }
        }
        if (flag==0)cout<<"0 0\n";
    }
    return 0;
}