#include <iostream>

using namespace std;

int n,a,b,c[200000];

int main()
{
    cin>>n;
   // cout<<"*";
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n;i++)
    {
        int x;
        x=c[i];
        if(x==25)
            a++;
        if(x==50)
        {
            if(a<1)
            {
           //     cout<<1<<" "<<a<<" "<<b<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
            else
            {
                b++;
                a--;
            }
        }
        if(x==100)
        {
            if(a<1)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if(a<3 && b<1)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else
            {
                if(b>0)
                {
                    b--;
                    a--;
                }
                else
                    a-=3;
            }
        }
    }
    cout<<"YES"<<endl;
}