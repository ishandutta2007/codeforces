#include <iostream>

using namespace std;

long long a,b,ans,x;

int main()
{
    cin>>a>>b;
    if(a==b)
    {
        cout<<"Equal"<<endl;
        return 0;
    }
    if(a>b)
    {
        for(int i=1;i<=b;i++)
        {
            while(x<a*i)
                x+=b;
            ans+=a*i-(x-b);
        }
        if(a*b<2*ans)
            cout<<"Dasha"<<endl;
        else if(a*b>2*ans)
            cout<<"Masha"<<endl;
        else
            cout<<"Equal"<<endl;
    }
    else
    {
        for(int i=1;i<=a;i++)
        {
            while(x<b*i)
                x+=a;
            ans+=b*i-(x-a);
        }
        if(a*b>2*ans)
            cout<<"Dasha"<<endl;
        else if(a*b<2*ans)
            cout<<"Masha"<<endl;
        else
            cout<<"Equal"<<endl;
    }
}