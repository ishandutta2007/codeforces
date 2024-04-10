#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int Have8=(N+3)/4;
        for(int i=0;i<N-Have8;i++)
            cout<<9;
        for(int i=0;i<Have8;i++)
            cout<<8;
        puts("");
    }
    return 0;
}