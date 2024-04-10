#include <iostream>
#include <algorithm>
using namespace std;

int a[6], s, k;

int solve2()
{
    for(int i=5;i>0;i--)
    {
        if(a[i]==a[i-1])
            return s-2*a[i];
    }
    return s;

}


int solve3()
{
    for(int i=5;i>0;i--)
    {
        if(a[i]==a[i-1] && a[i-1]==a[i-2])
            return s-3*a[i];
    }
    return s;

}

int main()
{
    for(int i=1;i<=5;i++)
        cin>>a[i], s+=a[i];

    sort(a+1, a+6);

    int min1=solve2();
    int min2=solve3();
    cout<<min(min1, min2)<<'\n';


    return 0;
}