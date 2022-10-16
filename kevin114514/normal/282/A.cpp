#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int X=0;
    while(n--)
    {
        string S;
        cin>>S;
        if(S[1]=='+')
            X++;
        else    X--;
    }
    cout<<X<<endl;
    return 0;
}