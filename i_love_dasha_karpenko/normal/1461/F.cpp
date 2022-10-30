#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
const ll INF = 1E10;
ll nxt[DIM],A[DIM],pref[DIM],dp[DIM],lst[DIM],mt[DIM];
ll Check(string s,char ch){
    for(char to:s)if (to==ch)return 1;
    return 0;
}
ll n;
void solve(){
    for(ll i = n;i>=1;--i){

        ll ptr = i;
        ll flag = 0;
        ll mult = A[i];
        ll last = i;
        dp[i] = A[i]+dp[i+1];
        while(nxt[ptr]>0){
            if (mult*A[nxt[ptr]]+dp[nxt[ptr]+1]>dp[i]){
                last = nxt[ptr];
                dp[i] = mult*A[nxt[ptr]]+dp[nxt[ptr]+1];
            }
            mult = min(DIM,mult*A[nxt[ptr]]);
            if (mult == DIM){
                last = lst[ptr];
                dp[i] = INF;
                break;
            }
            ptr = nxt[ptr];
        }

        mt[i] = last;
    }
    for(ll i = 1;i<=n;++i){
        if (i!=1)cout<<'+';
        for(ll j = i;j<=mt[i];++j){
            if (j!=i)cout<<'*';
            cout<<A[j];
        }
        i = mt[i];
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        pref[i] = pref[i-1]+A[i];
    }
    ll last = -1;

    for(ll i = n;i>=1;--i){

        if (A[i]==1)continue;
        if (A[i]==0){
            last = -1;
            continue;
        }
        nxt[i] = last;
        lst[i] = max(i,last);
        if (last!=-1)lst[i] = lst[last];
        last = i;
    }
    string s;
    cin>>s;
    if (Check(s,'+') && Check(s,'*'))solve();
    else if (Check(s,'+')){
        for(ll i = 1;i<=n;++i){
            cout<<A[i];
            if (i!=n)cout<<'+';
        }
        cout<<endl;
    }
    else if (Check(s,'*')){
        if (!Check(s,'-')){
            for(ll i = 1;i<=n;++i){
                cout<<A[i];
                if (i!=n)cout<<'*';
            }
            cout<<endl;
        }
        else{
            ll flag = 0;
            for(ll i = 1;i<=n;++i){
                if (A[i]==0 && flag==0){
                    if (i!=1)cout<<'-';
                    cout<<A[i];
                    flag = 1;
                    continue;
                }
                if (i!=1)cout<<'*'<<A[i];
                else cout<<A[i];
            }
            cout<<endl;
        }
    }
    else{
        for(ll i = 1;i<=n;++i){
            cout<<A[i];
            if (i!=n)cout<<'-';
        }
        cout<<endl;
    }
    return 0;
}