#include <iostream>

using namespace std;

int main()
{
    int n,sum;cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
    sum=a[0][0];
    for(int i=1;i<n;i++)
    {
        int x=sum-a[i][0];if(x<0){sum=a[i][0];continue;}
        x=(x/a[i][1])+1;sum=a[i][0]+(x*a[i][1]);
    }
    cout<<sum;
    return 0;
}