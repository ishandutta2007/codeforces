#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int X;
        cin>>X;
        if(X%9==0)
            cout<<X/9*10-1<<endl;
        else    cout<<X/9*10+X%9<<endl;
    }
    return 0;
}