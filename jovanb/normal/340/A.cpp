#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long x,y,a,b;
    cin>>x>>y>>a>>b;
    x=(x*y)/(__gcd(x,y));
    if(a%x!=0)a+=x-(a%x);
    b-=b%x;
    if(b<a)cout<<0;
    else cout<<(b-a)/x+1;
    return 0;
}