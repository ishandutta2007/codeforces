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
    char ch;
    long n,x,i,cnt=0,y;
    cin>>n>>x;
    for(i=0;i<n;++i)
    {
        cin>>ch>>y;
        if(ch=='+') x+=y;
        else
        {
            if(x<y) cnt++;
            else x-=y;
        }
    }
    cout<<x<<" "<<cnt;
    return 0;
}