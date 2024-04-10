#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mx=0;
    int N;
    cin>>N;
    while(N--)
    {
        int X;
        cin>>X;
        X=mx+X;
        mx=max(mx,X);
        cout<<X<<" ";
    }
    return 0;
}