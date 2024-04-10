#include <iostream>

using namespace std;
int n, s, k, c;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
    {cin>>k;
    if(s>0)
    {
        if(k>0) s+=k;
        if(k<0) s--;
    }
    else
    {
        if(k>0) s+=k;
        if(k<0) c++;
    }

    }




cout<<c;



    return 0;
}