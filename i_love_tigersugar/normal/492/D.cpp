#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)2e18+7LL;
const string ansX="Vanya";
const string ansY="Vova";
const string ansA="Both";
ll x,y;
int n;
string answer(ll a) {
    ll L=0;
    ll R=INF;
    while (true) {
        if (L==R) break;
        if (R-L==1) {
            if (L/x+L/y>=a) R--; else L++;
        }
        ll M=(L+R)>>1;
        if (M/x+M/y>=a) R=M; else L=M+1;
    }
    assert(L==R);
    if (R%x==0 && R%y==0) return (ansA);
    if (R%y==0) return (ansX);
    if (R%x==0) return (ansY);
}
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>x>>y;
    REP(zz,n) {
        ll a;
        cin>>a;
        cout<<answer(a)<<"\n";
    }
}