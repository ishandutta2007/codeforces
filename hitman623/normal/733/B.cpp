#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,a[100000][3],i,m1=0,m2=0,mx1=0,mx2=0,in1=0,in2=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2]=a[i][0]-a[i][1];
        if(a[i][2]<0) {m1+=a[i][2];if(a[i][2]<mx1){mx1=a[i][2];in1=i+1;}}
        else {m2+=a[i][2];if(a[i][2]>mx2){mx2=a[i][2];in2=i+1;}}
    }
    int n1=m1+m2-2*mx1;
    int n2=m1+m2-2*mx2;
    if(fabs(n1)>fabs(n2)) cout<<in1;
    else cout<<in2;
    return 0;
}