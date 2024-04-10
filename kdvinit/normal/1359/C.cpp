#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
    long long int h,c,tmp,k,val,v1,v2;
    cin>>h>>c>>tmp;
    h-=c;
    tmp-=c;
    if(6*tmp>=5*h) { cout<<1<<endl; return; }
    if(2*tmp<=h) { cout<<2<<endl; return; }
    k=2*tmp-h;
    v1=h/k;
    if(v1%2==0) v1--;
    v2=v1+2;
    if((h*(v1+v2))<=(2*k*v1*v2)) cout<<v1<<endl;
    else cout<<v2<<endl;
}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}