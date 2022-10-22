#include <iostream>

using namespace std;
int a[3],n,x;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;a[x]++;}
    if(a[1]==0){for(int i=0;i<n;i++)cout<<"2 ";return 0;}
    if(a[2]==0){for(int i=0;i<n;i++)cout<<"1 ";return 0;}
    cout<<"2 1 ";
    for(int i=1;i<a[2];i++)cout<<"2 ";
    for(int i=1;i<a[1];i++)cout<<"1 ";
    return 0;
}