#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 1007;
const ll INF = 10E16;
#define forn(i,n) for(ll i = 0;i<n;i++)
#define pb push_back
#define fi first
#define sc second
#define endl '\n'
const bool operator<(const pp &a,const pp &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
const bool operator>(const pp &a,const pp &b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi>b.fi;
}
const bool operator==(const pp &a,const pp &b){
    return a.fi==b.fi && a.sc==b.sc;
}
ll n,p;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>p;
    ll move = 0;
   // cout<<__builtin_popcount(28)<<endl;
    while(n>=move &&__builtin_popcount(n)>move){
        n-=p;
        move++;
    }
    if (__builtin_popcount(n)>move || n<move)cout<<"-1\n";
    else cout<<move<<endl;
    return 0;
}