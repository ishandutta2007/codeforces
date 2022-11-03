#include <iostream>

using namespace std;

int main()
{
    int k,d,i;
    cin>>k>>d;
    if(k<0)
    {
        cout<<"No solution";
        return 0;
    }
    if(d==0)
    {
        if(k==1)
        {
            cout<<0;
            return 0;
        }else
        {
            cout<<"No solution";
            return 0;
        }
    }
    if(d>0)
    {
        cout<<d;
        for(i=1;i<k;i++)
        {
            cout<<"0";
        }
    }
    return 0;
}