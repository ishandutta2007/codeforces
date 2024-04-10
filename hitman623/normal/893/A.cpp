#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    long n,i,a[101],p1=1,p2=2,p3=3,x;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        if(p1==x)
        {
            swap(p3,p2);
        }
        else if(p2==x) swap(p1,p3);
        else {cout<<"NO";return 0;}
    }
    cout<<"YES";
    return 0;
}