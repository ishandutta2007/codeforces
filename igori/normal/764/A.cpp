#include <iostream>

using namespace std;

int main()
{
    int z,m,n;
    cin>>n>>m>>z;
    int ans=0;
    for(int i=1; i<=z; i++)
    {
        if((i%n==0)&&(i%m==0))
            ans++;

    }
    cout<<ans;
}