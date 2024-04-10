#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long long a,b,c,z=0;
    cin>>a>>b>>c;
    a+=b+c;
    z=a/5;
    if(a%5!=0)z++;
    cin>>a>>b>>c;
    a+=b+c;
    z+=a/10;
    if(a%10!=0)z++;
    cin>>a;
    if(a<z)cout<<"NO";
    else cout<<"YES";
    return 0;
}