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
    long a,b,i,f=1;
    cin>>a>>b;
    if(b-a>10) cout<<"0";
    else
    {
        for(i=b;i>a;i--)
        f=(f*i)%10;
        cout<<f;
    }
    return 0;
}