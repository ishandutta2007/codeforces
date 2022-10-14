#include <iostream>
#include <algorithm>

using namespace std;
int n,k,c,d=86400,a[101];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){if(k<=0)break;k-=(d-a[i]);c++;}
    cout<<c;
    return 0;
}