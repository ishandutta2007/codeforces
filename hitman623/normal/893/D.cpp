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
long n,d,i,a[100005],x=0,cur;
int main()
{
    io
    cin>>n>>d;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        x+=a[i];
        if(a[i]==0)
        {
            if(x<0)
            x=0;
        }
        if(x>d) {cout<<-1;return 0;}
    }
    x=0;
    for(i=0;i<n;++i)
    {
        x+=a[i];
        if(a[i]==0)
        {
            if(x<0)
            {
                cur++;
                x=d;
            }
        }
        if(x>d) x=d;
    }
    cout<<cur;
    return 0;
}