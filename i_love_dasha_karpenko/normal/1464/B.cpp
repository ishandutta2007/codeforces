#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll A[DIM],res = INF,suf[DIM][2],pref[DIM][2],dp[DIM],v[2],dp_pref[DIM],n;
void Check(ll symb){
    for(ll i = 1;i<=n;++i){
        pref[i][0] = pref[i-1][0];
        pref[i][1] = pref[i-1][1];
        if (A[i]>=0){
            pref[i][A[i]]++;
        }
        else{
            pref[i][symb]++;
        }
    }
    for(ll i = n;i>=1;--i){
        suf[i][0] = suf[i+1][0];
        suf[i][1] = suf[i+1][1];
        dp[i] = dp[i+1];

        if (A[i]>=0){
            suf[i][A[i]]++;
            dp[i]+=pref[i-1][A[i]^1]*v[A[i]];
        }
        else{
            suf[i][symb^1]++;
            dp[i]+=pref[i-1][symb]*v[symb^1]+suf[i+1][symb]*v[symb];
            dp[i]-=suf[i+1][symb^1]*v[symb^1];
        }
    }
    ll cnt = 0;

    for(ll i = 0;i<=n;++i){
        if (i!=0){
            if (A[i]>=0){
                cnt+=pref[i][A[i]^1]*v[A[i]];
            }
            else{
                cnt+=pref[i][symb^1]*v[symb];
            }
        }
        res = min(res,dp[i+1]+cnt);
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    n = s.length();
    cin>>v[1]>>v[0];
    for(ll i = 0;i<s.length();++i){
        if (s[i]=='?')
            A[i+1] = -1;
        else
            A[i+1] = s[i]-'0';

    }
    Check(0);
    Check(1);
    cout<<res<<endl;
    return 0;
}