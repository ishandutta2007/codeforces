#include <iostream>

using namespace std;

int main()
{
    long long n,k;
    long long brojac=0;
    cin>>n>>k;
    if(k>=1)brojac+=1;
    if(k>=2)brojac+=n*(n-1)/2*1;
    if(k>=3)brojac+=n*(n-1)*(n-2)/6*2;
    if(k>=4)brojac+=n*(n-1)*(n-2)*(n-3)/24*9;
    cout<<brojac;
    return 0;
}