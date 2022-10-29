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
    long a;
    cin>>a;
    if(a==1)
    cout<<"1 1\n1";
    else
    cout<<2*(a-1)<<" 2\n1 2";
    return 0;
}