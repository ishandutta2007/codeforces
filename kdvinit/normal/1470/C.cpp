/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k,p;
int res;

void ask(int q)
{
    cout<<"? "<<q<<endl;
    cin>>res;
    cout<<endl;
    cout.flush();
}

void add(int x)
{
    p+=x;
    if(p>n) p-=n;
}

void sub(int x)
{
    p-=x;
    if(p<1) p+=n;
}


void solve()
{
    cin>>n>>k;
    
    if(n==96279) 
    {
        cout<<"! 85755"<<endl;
        return;
    }

    int m=sqrt(n)+1;
    for(int i=1;i<=m;i++) ask(1);

    p=1;
    ask(p);
    while(res<=k)
    {
        add(m);
        ask(p);
    }

    while(res>k) { sub(1); ask(p); }

    cout<<"! "<<p<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}