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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,a,b,c=0,i,cnt=0,x;
    cin>>n>>a>>b;
    for(i=0;i<n;++i)
    {
        cin>>x;
        if(x==1)
        {
            if(a>0) a--;
            else if(b>0) b--,c++;
            else if(c>0) c--;
            else cnt++;
        }
        else
        {
            if(b>0) b--;
            else cnt++,cnt++;
        }
    }
    cout<<cnt;
    return 0;
}