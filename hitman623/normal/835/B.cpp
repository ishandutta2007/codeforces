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
    string n;
    long k,c=0;
    cin>>k>>n;
    for(c=0;c<n.length();++c)
    k-=n[c]-'0';
    c=0;
    sort(n.begin(),n.end());
    while(k>0)
    {k-='9'-n[c];
    c++;}
    cout<<c;
    return 0;
}