#include <iostream>

using namespace std;

int n, a[100007], mina=1000000, mini, o;

int main()
{
cin>>n;

for(int i=0;i<n;i++)
{
    cin>>a[i];
    if(a[i]<mina)
        mina=a[i], mini=i;
}
    for(int i=0;i<n-1;i++)
        if(a[i] > a[i+1]) o++, mini=i+1;

    if((o!=0 && a[n-1]>a[0]) || o>1)
    cout<<-1;
    else
    cout << (n-mini)%n;
    return 0;
}