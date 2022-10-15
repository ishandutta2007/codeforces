#include<bits/stdc++.h>
using namespace std;
int main()
{
    int X;
    cin>>X;
    while(X--)
    {
        int Y;
        cin>>Y;
        if(Y==1)
            puts("-1");
        else
        {
            cout<<2;
            for(int i=1;i<Y;i++)
                cout<<3;
            puts("");
        }
    }
    return 0;
}