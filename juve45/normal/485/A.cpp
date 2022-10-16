#include <iostream>

using namespace std;

int X[100004], x, m, i;

int main()
{
cin>>x>>m;
    i=x%m;
    //X[i]=1;
    while(X[i]==0 && x!=0)
    {

        x+=i;
        x%=m;
        X[i]=1;
        i=x;

        if(x==0)
        {
            cout<<"Yes";
            return 0;
        }
        if(X[i]!=0)
        {
                cout<<"No";
                return 0;
        }


    }



    return 0;
}