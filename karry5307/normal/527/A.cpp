#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll length,width;
ll calc(ll length,ll width)
{
    if(length<width)
    {
        return calc(width,length);
    }
    if(length==0||width==0)
    {
        return 0;
    }
    return calc(width,length%width)+length/width;
}
int main()
{
    cin>>length>>width;
    cout<<calc(length,width);
}