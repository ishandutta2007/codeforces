#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long a,b,a1=0,b1=0,x,y,z,nula=0;
    cin>>a>>b;
    cin>>x>>y>>z;
    a1+=x*2;
    a1+=y;
    b1+=y;
    b1+=3*z;
    cout<<max(nula,a1-a)+max(nula,b1-b);
    return 0;
}