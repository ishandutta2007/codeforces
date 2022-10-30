#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM],pref[3][DIM],suf[3][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
    }
    ll sum = 0;
    for(ll i = 1;i<=n;++i){

        sum+=A[i];
    }


    for(ll i = 1;i<=n;++i){
        pref[0][i] = pref[0][i-1]+A[i];
        pref[1][i] = pref[1][i-1]+A[i];
        pref[2][i] = pref[2][i-1]+A[i];
        if (i>=k){
            pref[1][i] = max(pref[1][i],pref[0][i-k]+k);
            pref[2][i] = min(pref[2][i],pref[0][i-k]);
        }
        else{
            pref[1][i] = i;
            pref[2][i] = 0;
        }
    }
    if (pref[1][n]==n || pref[2][n]==0){
        cout<<"tokitsukaze\n";
        return 0;
    }
    for(ll i = n;i>=1;--i){
        suf[0][i] = suf[0][i+1]+A[i];
        suf[1][i] = suf[1][i+1]+A[i];
        suf[2][i] = suf[2][i+1]+A[i];
        if (i+k<=n+1){
            suf[1][i] = max(suf[1][i],suf[0][i+k]+k);
            suf[2][i] = min(suf[2][i],suf[0][i+k]);
        }
        else{
            suf[1][i] = n-i+1;
            suf[2][i] = 0;
        }
    }
    ll flag = 0;
    for(ll i = 1;i<=n-k;++i){
        if (!((pref[1][i-1]==i-1 && suf[0][i+k]==(n-i-k+1)) || (pref[0][i-1]==i-1 && suf[1][i+k]==(n-i-k+1))))
            flag = 1;
        if (!((pref[2][i-1]==0 && suf[0][i+k]==0) || (pref[0][i-1]==0 && suf[2][i+k]==0)))
        flag = 1;

    }
    if (flag)
    cout<<"once again\n"<<endl;
    else{
        cout<<"quailty\n";
    }
    return 0;

}