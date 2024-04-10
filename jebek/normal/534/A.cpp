#include <iostream>

using namespace std;

int n;
int main()
{
    cin>>n;
    if(n==2)
    {
        cout<<1<<endl<<1<<endl;
    }
    else if(n==3)
    {
        cout<<2<<endl<<"1 3"<<endl;
    }
    else
    {
        cout<<n<<endl;
        for(int i=2;i<=n;i+=2)
            cout<<i<<" ";
        for(int i=1;i<=n;i+=2)
            cout<<i<<" ";
        cout<<endl;
    }
}