//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E3+7;
ll A[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll cnt = 0;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            A[i] = ch-'0';
            if (A[i]==0)
                ++cnt;
        }

        ll flag = 0;
        for(ll i = 1;i<=n/2;++i){
            if (A[i]!=A[n-i+1])
                ++flag;
        }
        cnt-=flag;
        ll c1 = 0,c2 = 0;
        if (n%2 && A[n/2+1]==0){
            if (cnt>1)
            c1 = 0,c2 = 1;
            else c1 = 1;
        }
        else if (cnt>0){
            if (flag==0)
                c1 = 2,c2 = 0;
            else c1 = 0,c2 = 0;
        }
        c2+=flag;
        if (c1<c2 )
            cout<<"ALICE\n";
        else if (c2<c1)
            cout<<"BOB\n";
        else cout<<"DRAW\n";
    }
    return 0;
}