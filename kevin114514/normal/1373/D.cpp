#include<bits/stdc++.h>
using namespace std;
#define int long long
int X[200200];
signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>X[i];
        int Sum=0,Min=0,Ans=0;
        for(int i=0;i+1<N;i+=2)
        {
            Sum+=X[i+1];
            Sum-=X[i];
            Ans=max(Ans,Sum-Min);
            Min=min(Min,Sum);
        //  cout<<Sum<<" "<<Min<<" "<<Ans<<endl;
        }
        Sum=0;
        Min=0;
        for(int i=1;i+1<N;i+=2)
        {
            Sum-=X[i+1];
            Sum+=X[i];
            Ans=max(Ans,Sum-Min);
            Min=min(Min,Sum);
        //	cout<<Sum<<" "<<Min<<" "<<Ans<<endl;
        }
        for(int i=0;i<N;i+=2)
            Ans+=X[i];
        cout<<Ans<<endl;
    }
    return 0;
}