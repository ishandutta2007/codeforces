#include <iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

long double x,y,r,a,c,b,d;

int main()
{
    cin>>x>>y>>r>>a>>b>>c;
    cout<<fixed<<setprecision(8);
    d=sqrt((a-x)*(a-x)+(b-y)*(b-y));
    if(d+min(r,c)<=max(r,c))
    {
        cout<<(max(r,c)-d-min(r,c))/2.0<<endl;
        return 0;
    }
    if(d<r+c)
        d=r+c;
    cout<<(d-r-c)/2.0<<endl;
}