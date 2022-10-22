#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long a,b,c;
    cin>>a>>b>>c;
    long x,y,z;
    for(z=0;z<=a;z++){
        x=a-z;
        y=b-x;
        if(y+z==c && y>=0 && x>=0){cout<<x<<" "<<y<<" "<<z;return 0;}
    }
    cout<<"Impossible";
    return 0;
}