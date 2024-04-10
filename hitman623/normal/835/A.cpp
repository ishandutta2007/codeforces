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
    long s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    if(v1*s+2*t1<v2*s+2*t2)
    cout<<"First";
    else if(v1*s+2*t1>v2*s+2*t2)
    cout<<"Second";
    else cout<<"Friendship";
    return 0;
}