#include <iostream>

using namespace std;
int n, sol;
int main()
{
    int a, b, c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {cin>>a>>b>>c;
    if(a+b+c>=2)
    sol++;
    }
    cout<<sol;
    return 0;
}