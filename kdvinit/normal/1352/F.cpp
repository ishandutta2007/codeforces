#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        if(n0!=0)
        {
            for(int i=0;i<n0+1;i++) cout<<0;
        }
        if(n0==0 && n1!=0) cout<<0;
        if(n2!=0)
        {
            for(int i=0;i<n2+1;i++) cout<<1;
        }
        if(n2==0 && n1!=0) cout<<1;
        int y=n1/2;
        if(n1%2==1)
        {
            for(int i=0;i<y;i++) cout<<0<<1;
        }
        if(n1%2==0 && n1!=0)
        {
            for(int i=0;i<y-1;i++) cout<<0<<1;
            cout<<0;
        }

        cout<<endl;
    }
    return 0;
}