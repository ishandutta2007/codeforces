#include<iostream>
#define MAX   100100
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
inline ll ceil(ll a,ll b) {
    return (a/b+(a%b>0));
}
int main(void) {
    ll n,a,b,x,y;
    cin>>n>>a>>b;
    n*=6;
    if (a*b>=n) {
        cout<<a*b<<endl<<a<<" "<<b;
        return 0;
    }
    if (ceil(n,b)*b<ceil(n,a)*a) {
        x=ceil(n,b);
        y=b;
    }
    else {
        x=a;
        y=ceil(n,a);
    }
    REP(da,MAX) if (x*y>(a+da)*max(b,ceil(n,a+da))) {
        x=a+da;
        y=max(b,ceil(n,a+da));
    }
    REP(db,MAX) if (x*y>(b+db)*max(a,ceil(n,b+db))) {
        x=max(a,ceil(n,b+db));
        y=b+db;
    }
    cout<<x*y<<endl<<x<<" "<<y;
    return 0;
}