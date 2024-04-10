#include <iostream>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    if(r==1&&c==1)
    {
        cout<<0;
        return 0;
    }
    for(int j=0;j<c;j++)
    {
        cout<<j+2<<" ";
    }
    cout<<endl;
    if(c==1)
    {
        for(int i=1;i<r;i++)
        {
            cout<<i+2<<endl;
        }
        return 0;
    }
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<(c+i+1)*(j+2)<<" ";
        }
        cout<<endl;
    }
    return 0;
}