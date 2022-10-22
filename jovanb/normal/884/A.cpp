#include <iostream>

using namespace std;

int main()
{
    long x,a,r=-5;
    int n,i;
    cin>>n>>x;
    for(i=1;i<=n;i++){
        cin>>a;
        x-=(86400-a);
        if(x<=0 && r==-5)r=i;
    }
    cout<<r;
    return 0;
}