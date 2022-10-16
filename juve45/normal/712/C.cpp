#include <iostream>

using namespace std;
long long x, y, ans;
int main()
{
cin>>x>>y;

long long Min=y, Med=y, Max=y;

while(Min<x)
{
    Min=Max+Med-1;
    swap(Min, Max);
    swap(Min, Med);
    ans++;
}
cout<<ans<<'\n';


    return 0;
}