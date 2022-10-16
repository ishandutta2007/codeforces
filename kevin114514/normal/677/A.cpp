#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    int Ans=0;
    while(N--)
    {
        int X;
        cin>>X;
        if(X>K)
            Ans++;
        Ans++;
    }
    cout<<Ans<<endl;
    return 0;
}