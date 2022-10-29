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
    char a,b;
    cin>>a>>b;
    long n;
    cin>>n;
    n%=4;
    if(n==0 || n==2)
    cout<<"undefined";
    else if(n==1)
    {
        if((a=='<' && b=='^') || (a=='^' && b=='>') || (a=='>' && b=='v') || (a=='v' && b=='<'))
        cout<<"cw";
        else cout<<"ccw";
    }
    else if(n==3)
    {
        if((a=='<' && b=='^') || (a=='^' && b=='>') || (a=='>' && b=='v') || (a=='v' && b=='<'))
        cout<<"ccw";
        else cout<<"cw";
    }
    return 0;
}