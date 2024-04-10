#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 2E5+7;
const ll INF = 1E9;
ll A[DIM],B[DIM],R[DIM];
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,k;
    cin>>a>>b>>k;
    ll n = a+b;
    if (b==1){
        if (k!=0){
            cout<<"No\n";
            return 0;
        }
        cout<<"Yes\n";
        cout<<1;
        for(ll i = 1;i<n;++i)cout<<0;
        cout<<endl;
        cout<<1;
        for(ll i = 1;i<n;++i)cout<<0;
        cout<<endl;
        return 0;
    }
    if (a==0){
        if (k!=0){
            cout<<"No\n";
            return 0;
        }
        cout<<"Yes\n";
        for(ll i = 1;i<=n;++i)cout<<1;
        cout<<endl;
        for(ll i = 1;i<=n;++i)cout<<1;
        cout<<endl;
        return 0;
    }

    for(ll i = 1;i<=b;++i){
        A[i] = 1;
    }
    B[1] = 1;

    if (k>n-2){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    if ( k<b){
        for(ll i = 1;i<=b-k;++i)B[i] = 1;
        ll cnt = k;
        ll ptr = b+1;
        while(cnt){
            B[ptr--] = 1;
            --cnt;
        }
       // return 0;
    }
    else{
        B[k+2] = 1;
        ll ptr = b;
        ll cnt = b-2;
        while(cnt>0){
            B[ptr--] = 1;
            --cnt;
        }
    }
    for(ll i = 1;i<=n;++i)
        cout<<A[i];
    cout<<endl;
    for(ll i = 1;i<=n;++i)
        cout<<B[i];
    cout<<endl;
    return 0;
}