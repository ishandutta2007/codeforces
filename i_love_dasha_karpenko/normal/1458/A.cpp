#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 fgdfgdg
const ll DIM = 2E5+7;
ll A[DIM];
ll GCD(ll a,ll b){
    if (a==0 || b==0)return a+b;
    return GCD(b%a,a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    ll gcd = A[2]-A[1];
    for(ll i = 2;i<=n;++i){
        if (i==2)gcd = A[i]-A[i-1];
        else gcd = GCD(A[i]-A[i-1],gcd);
    }
    for(ll i = 1;i<=m;++i){
        ll x;
        cin>>x;
        if (n!=1)
        cout<<GCD(A[1]+x,gcd)<<' ';
        else cout<<A[1]+x<<' ';
    }
    cout<<endl;
    return 0;
}