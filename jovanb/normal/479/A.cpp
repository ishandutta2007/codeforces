#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    
    int a,b,c,maxi;
    cin>>a>>b>>c;
    maxi=a+b+c;
    maxi=max(maxi,a*b*c);
    maxi=max(maxi,a*b+c);
    maxi=max(maxi,a*(b+c));
    maxi=max(maxi,a+b*c);
    maxi=max(maxi,(a+b)*c);
    cout<<maxi;
    return 0;
}