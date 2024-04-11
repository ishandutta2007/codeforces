#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second

using namespace std;

main()
{
    int x, y;
    cin>>x>>y;
    int a=abs(x)+abs(y);
    if ((x>0) and (y>0))
        cout<<"0 "<<a<<" "<<a<<" 0\n";
    if ((x<0) and (y>0))
        cout<<-a<<" 0 0 "<<a<<"\n";
    if ((x>0) and (y<0))
        cout<<"0 "<<-a<<" "<<a<<" 0\n";
    if ((x<0) and (y<0))
        cout<<-a<<" 0 0 "<<-a<<"\n";
}