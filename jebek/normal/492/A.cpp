#include <iostream>

using namespace std;
int t,n,x;

int main()
{
    cin>>n;
    for(int i=1;n>=0;i++)
    {
        x+=i;
        n-=x;
        t++;
    }
    cout<<t-1<<endl;
}