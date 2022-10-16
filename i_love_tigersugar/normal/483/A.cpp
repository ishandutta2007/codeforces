#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
int main(void) {
    ll l,r;
    cin>>l>>r;
    if (r-l+1<3) cout<<-1;
    else if (r-l+1==3) {
        if (gcd(l,r)==1) cout<<-1; else cout<<l<<" "<<l+1<<" "<<l+2;
    } else {
        while (l%2==1) l++;
        cout<<l<<" "<<l+1<<" "<<l+2;
    }
    return 0;
}