#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 2E5+7;
const ll INF = 1E18;
ll A[DIM],P[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    ll l = 1,r = n;
    while(l!=r){
        ll tm = (l+r+1)/2;
        ll mi = INF;
        ll sum = 0,flag = 0;
        for(ll i = 1;i<k;++i){
            if (A[i]<tm)--sum;
            else ++sum;
            P[i] = sum;
        }
        for(ll i = k;i<=n;++i){
            if (A[i]<tm)--sum;
            else ++sum;
            mi = min(mi,P[i-k]);
            if (sum-mi>0)flag = 1;
            P[i] = sum;
        }
        if (flag)l = tm;
        else r = tm-1;
    }
    cout<<l<<endl;
    return 0;
}