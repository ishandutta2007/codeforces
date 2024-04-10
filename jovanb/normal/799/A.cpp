#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n,t,k,d,t1,v;
    cin>>n>>t>>k>>d;
    t1=t*(n/k);
    if(n%k!=0)t1+=t;
    if(d>=t1){cout<<"NO";return 0;}
    t1--;
    v=(t1/t+(t1-d)/t);
    v*=k;
    if(v>=n){cout<<"YES";}
    else cout<<"NO";
    return 0;
}