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
    vll v;
    long n,l,r,i,cur=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>l>>r;
        v.pb({l,-1});
        v.pb({r,1});
    }
    sort(v.begin(),v.end());
    for(i=0;i<2*n;++i)
    {
        cur-=v[i].y;
        if(cur>2) {cout<<"NO";exit(0);}
    }
    cout<<"YES";
    return 0;
}