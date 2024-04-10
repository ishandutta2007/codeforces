#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>N>>K;
        if(N%2==0)
        {
            cout<<N+K*2<<endl;
            continue;
        }
        for(int i=2;i<=N;i++)
            if(N%i==0)
            {
                cout<<N+i+K*2-2<<endl;
                break;
            }
    }
    return 0;
}