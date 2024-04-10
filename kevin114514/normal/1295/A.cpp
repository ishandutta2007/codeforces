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
        if(N%2==1)
        {
            cout<<7;
            N-=3;
        }
        N/=2;
        for(int i=0;i<N;i++)
            cout<<1;
        cout<<endl;
    }
    return 0;
}