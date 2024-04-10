#include <iostream>
#include <cstring>
using namespace std;
int n, m, k, l, d, sol;

int main()
{
cin>>k>>l>>n>>m>>d;
for(int i=1;i<=d;i++)
    if(i%k==0 || i%l==0 || i%n==0 || i%m==0) sol++;
    cout<<sol;
    return 0;

}