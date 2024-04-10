#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n;
    cin>>n;
    if(n==12){cout<<4<<" "<<8;return 0;}
    if(n%2==0)cout<<6<<" "<<n-6;
    else cout<<9<<" "<<n-9;
    return 0;
}