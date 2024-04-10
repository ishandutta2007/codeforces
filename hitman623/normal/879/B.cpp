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
    long n,k,a[1001],i,cur,c=0;
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    cur=a[0];
    for(i=1;i<n;++i)
    {
        if(cur>a[i]) c++;
        else cur=a[i],c=1;
        if(c>=k) {cout<<cur;exit(0);}
    }
    cout<<cur;
    return 0;
}