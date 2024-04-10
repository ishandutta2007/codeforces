#include <iostream>

using namespace std;

int main()
{
    int a[1005],n,c=0;
    cin>>n;for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n-1;i++)if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))c++;
    cout<<c;
    return 0;
}