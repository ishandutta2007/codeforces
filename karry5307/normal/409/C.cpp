#include<bits/stdc++.h>
using namespace std;
int nitr,acid,merc,lead,van;
int main()
{
    cin>>nitr>>acid>>merc>>lead>>van;
    cout<<min(min(min(min(nitr,acid),merc/2),lead/7),van/4);
}