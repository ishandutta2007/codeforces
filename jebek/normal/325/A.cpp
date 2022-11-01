#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,p=0,x1,x2,y1,y2,mi1=1000000000,mi2=100000000,ma1=0,ma2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        p+=(x2-x1)*(y2-y1);
        mi1=min(mi1,x1);
        mi2=min(mi2,y1);
        ma1=max(ma1,x2);
        ma2=max(ma2,y2);
    }
    if(p==(ma1-mi1)*(ma2-mi2) && (ma1-mi1)==(ma2-mi2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}