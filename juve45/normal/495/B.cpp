#include <iostream>

using namespace std;

int a, b, ans;

int main()
{
    cin>>a>>b;
    if(a==b)
    {
        cout<<"infinity\n";
    }
    else {
        if(a<b)
            cout<<"0\n";
        else
        {
            int k=a-b, i;
            for(i=1;i*i<k;i++)
            {
                if(k%i==0)
                {
                    if(i>b)ans++;
                if(k/i>b)ans++;
                }
            }
            if(k%i==0 && i>b && i*i==k)ans++;
            cout<<ans;
        }
    }


    return 0;
}