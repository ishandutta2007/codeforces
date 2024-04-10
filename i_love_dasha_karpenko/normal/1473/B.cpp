#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        string cur = "";
        ll ff = 0;
        for(ll len = 1;len<=t.length();++len){
            cur+=s;
            if (cur.length()%t.length()!=0)continue;
            ll flag = 0;
            for(ll pos = 0;pos<cur.length();pos+=t.length()){
                for(ll j = pos;j<pos+t.length();++j){
                    if (cur[j]!=t[j-pos]){
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag==0){
                cout<<cur<<endl;
                ff = 1;
                break;
            }
        }
        if (ff==0)cout<<"-1\n";
    }
    return 0;
}