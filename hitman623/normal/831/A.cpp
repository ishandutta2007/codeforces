#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,i,a[102],f=1;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=1;i<n;++i)
    if(a[i]>a[i-1])
    {
        if(f!=1)
        {cout<<"NO";exit(0);}
    }
    else if(a[i]==a[i-1])
    {
        if(f==1) f=2;
        else if(f!=2) {cout<<"NO";exit(0);}
    }
    else f=3;
    cout<<"YES";
    return 0;
}