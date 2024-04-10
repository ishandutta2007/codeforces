#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    int lst=-1;
    long long Ans=1,XX=0;
    for(int i=0;i<N;i++)
    {
        int X;
        cin>>X;
        if(X>N-K)
        {
            if(lst!=-1)
                Ans=Ans*(i-lst)%998244353;
            lst=i;
            XX+=X;
        }
    }
    cout<<XX<<" "<<Ans<<endl;
    return 0;
}