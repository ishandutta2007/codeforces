/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int b,w;
    cin>>b>>w;

    int x=min(b,w);
    int y=max(b,w);

    if(y>(3*x+1)) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;

    int add=0;
    if(y==b) add=1;

    for(int i=1;i<=(2*x);i++)
    {
        cout<<3<<" "<<(i+add)<<endl;
    }

    y-=x;

    if(y<=0) return;
    cout<<3<<" "<<((2*x)+1+add)<<endl;
    y--;
    if(y<=0) return;

    for(int i=1;i<=min(y,x);i++)
    {
        cout<<2<<" "<<( (2*i)+add )<<endl;
    }

    y-=x;
    if(y<=0) return;

    for(int i=1;i<=min(y,x);i++)
    {
        cout<<4<<" "<<( (2*i)+add )<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}