#include <iostream>

using namespace std;

int main()
{
    long long n,i,k,a[100000],p=0,f=1;
    cin>>n>>k;
    for(i=0;i<n;++i)
       {
        cin>>a[i];
        if(((i+1)*(i+2))/2>=k && f==1) {p=i+1;f=0;}
        }
    long long h=k-(p*(p-1))/2 -1;
    cout<<a[h];
    return 0;
}