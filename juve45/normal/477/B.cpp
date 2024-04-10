#include <iostream>

using namespace std;
int n, k;
int main()
{
cin>>n>>k;

cout<<(6*n-1)*k<<'\n';


for(int i=0;i<n;i++)
{
    cout<<k*(6*i+1)<<' ';
    cout<<k*(6*i+2)<<' ';
    cout<<k*(6*i+3)<<' ';
    cout<<k*(6*i+5)<<'\n';
}


    return 0;
}