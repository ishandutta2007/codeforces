#include<bits/stdc++.h>
using namespace std;
int X[400400];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>X[i];
        int mx=0,mn=1000000000;
        for(int i=0;i<N;i++)
            if(X[i]==-1)
            {
                if(i&&X[i-1]!=-1)
                    mx=max(mx,X[i-1]),
                    mn=min(mn,X[i-1]);
                if(i<N-1&&X[i+1]!=-1)
                    mx=max(mx,X[i+1]),
                    mn=min(mn,X[i+1]);
            }
        int x=(mx+mn)/2;
        for(int i=0;i<N;i++)
            if(X[i]==-1)
                X[i]=x;
        int Ans=0;
        for(int i=0;i<N-1;i++)
            Ans=max(Ans,abs(X[i]-X[i+1]));
        cout<<Ans<<" "<<x<<endl;
    }
    return 0;
}