#include <iostream>
#include <vector>

using namespace std;

long long n,i,j,sn,k;

int main()
{
    cin>>n;
    sn=2;
    cout<<"2\n";
    for (i=2; i<=n; i++)
    {
        cout<<i*(i+1)*(i+1)-i+1<<'\n';
    }
}