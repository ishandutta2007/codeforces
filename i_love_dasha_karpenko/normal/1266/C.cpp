#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 200007+7;
const ll INF = 10E10;

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    if(n==m && n==1){
        cout<<"0\n";
        return 0;
    }
    ll mult = 1;
    if (m==1){
        forn(i,n)cout<<i+1<<endl;
        return 0;
    }
    forn(i,n){
        forn(j,m)cout<<(j+1)*mult<<' ';
        cout<<endl;
        if (i==1)
        mult+=m+1;
        else mult++;
    }
    return 0;
}