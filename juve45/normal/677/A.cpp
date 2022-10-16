#include <iostream>

using namespace std;
int n, h, x;
int main()
{
cin>>n>>h;
int sol=0;
for(int i=1;i<=n;i++)
{
    cin>>x;
    sol++;
    if(x>h)
        sol++;
}

cout<<sol<<'\n';

    return 0;
}