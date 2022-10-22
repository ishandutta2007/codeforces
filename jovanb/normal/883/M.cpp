#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1,y1,x2,y2,x,y;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)x=2;
    else(x=abs(x1-x2)+1);
    if(y1==y2)y=2;
    else(y=abs(y1-y2)+1);
    cout<<2*(x+y);
    return 0;
}