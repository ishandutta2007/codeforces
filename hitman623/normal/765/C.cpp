#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
    long long k,a,b,a1,b1,ans=0;
    cin>>k>>a>>b;
    a1=a/k;
    b1=b/k;
    a%=k;
    b%=k;
    if(a1>0 && b1>0) cout<<a1+b1;
    else if(a1==0 && b1>0)
    {
        if(b==0) cout<<b1;
        else cout<<-1;
    }
    else if(b1==0 && a1>0)
    {
        if(a==0) cout<<a1;
        else cout<<-1;
    }
    else cout<<-1;
    return 0;
}