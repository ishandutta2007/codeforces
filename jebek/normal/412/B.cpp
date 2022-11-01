#include <iostream>
#include<algorithm>

using namespace std;

int n,k,a[200];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<a[n-k]<<endl;
}