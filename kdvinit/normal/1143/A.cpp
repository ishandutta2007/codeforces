#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a0=0,a1=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==0) a0=i;
        else a1=i;
    }
    cout<<min(a0,a1)<<endl;
    return 0;
}