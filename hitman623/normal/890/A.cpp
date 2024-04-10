#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define sz(x) 1LL*x.size()
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    long a[6],i,d=(1<<6),ss=0,j;
    for(i=0;i<6;++i)
    cin>>a[i],ss+=a[i];
    for(i=0;i<d;++i)
    {
        long s=0,c=0;
        for(j=0;j<6;++j)
        if(i&(1<<j))
        s+=a[j],c++;
        if(2*s==ss && c==3) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}