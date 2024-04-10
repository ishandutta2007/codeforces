//This code is based on albertg's solution
#include<bits/stdc++.h>
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
vector<ll> getPoly(ll a,ll b) {
    vector<ll> res;
    while (b>0) {
        res.push_back(b%a);
        b/=a;
    }
    return (res);
}
ll getValue(const vector<ll> &poly,ll t) {
    ll mul=1;
    ll res=0;
    FORE(it,poly) {
        if (INF/mul<*it || res+*it*mul>INF) return (INF);
        res+=*it*mul;
        mul=INF/mul<t?INF:mul*t;
    }
    return (res);
}
bool isPw(ll a,ll b) {
    ll mul=a;
    while (mul<INF) {
        if (mul==b) return (true);
        mul=INF/a<mul?INF:mul*a;
    }
    return (false);
}
int answer(void) {
    ll t,a,b;
    cin>>t>>a>>b;
    if (t>1) return ((a==b)+(a>1 && getValue(getPoly(a,b),t)==a));
    if (a==1 && b==1) return (-1);
    if (a==1 && b!=1) return (0);
    if (isPw(a,b)) return (1);
    return (getValue(getPoly(a,b),t)==a);
}
int main(void) {
    srand(time(NULL));
    ios::sync_with_stdio(rand()&1);
    int x=answer();
    if (x<0) cout<<"inf"; else cout<<x;
    cout<<endl;
    return 0;
}