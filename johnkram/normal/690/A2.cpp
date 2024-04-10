#include<iostream>
using namespace std;
int n,i;
int main()
{
    cin>>n;
    if(n&1)n=n>>1;
    else
    {
        for(i=1;i<=n;i<<=1);
        n=(n-(i>>1))>>1;
    }
    cout<<n<<endl;
    return 0;
}