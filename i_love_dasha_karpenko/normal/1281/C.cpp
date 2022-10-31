#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
const ll MOD = 10E8+7;
ll gi(char ch){
    return ch-'0';
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll x; string s;
        cin>>x>>s;
        ll l = 0,num = 0,res = s.length(),ptr = 0;
        while(l!=x){
            l++;
            num = gi(s[l-1]);
            num--;
            if (s.length()>=x){
                ll addlen = (res-l)*num;
                if (addlen<0)addlen+=MOD;
                res=(res+addlen)%MOD;
            }
            else{
                ll addlen = (res-l)*num;
                ptr = l;
                while(1+s.length()<=x && addlen>0){
                    s+=s[ptr];
                    res++;
                    ptr++;
                    addlen--;
                }
                res = (res+addlen)%MOD;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3