#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,c,mini;
    cin>>n>>a>>b>>c;
    mini=min(a,min(b,c));
    if(a==mini)cout<<(n-1)*a;
    else if(b==mini)cout<<(n-1)*b;
    else if(n==1)cout<<0;
    else if(a<b)cout<<(n-2)*c+a;
    else cout<<(n-2)*c+b;

    return 0;
}