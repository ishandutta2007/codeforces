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
    long n,q;
    cin>>q;
    while(q--)
    {
        cin>>n;
        if(n==11) {cout<<-1<<endl;continue;}
        if(n%4==0)
        cout<<n/4;
        else if(n%4==1)
        {
            if(n/4-1>0)
            cout<<n/4-1;
            else cout<<-1;
        }
        else if(n%4==2)
        {
            if(n/4)
            cout<<n/4;
            else cout<<-1;
        }
        else
        {
            if(n/4-1>0)
            cout<<n/4-1;
            else cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}