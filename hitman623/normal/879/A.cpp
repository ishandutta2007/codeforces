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
    long n,s,d,cur,i;
    cin>>n;
    cin>>s>>d;
    cur=s;
    for(i=1;i<n;++i)
    {
        cin>>s>>d;
        cur=s+d*((max(0LL,cur-s+1)+d-1)/d);
    }
    cout<<cur;
    return 0;
}