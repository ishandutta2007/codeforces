#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int X;
        cin>>X;
        if(X<4)
            cout<<4-X<<endl;
        else if(X%2)
            cout<<"1\n";
        else    cout<<"0\n";
    }
    return 0;
}