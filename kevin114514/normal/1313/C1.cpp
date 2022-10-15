#include<bits/stdc++.h>
using namespace std;
int X[100100];
int main()
{
    int N;
    cin>>N;
    long long mx=0;
    int p;
    for(int i=0;i<N;i++)
        cin>>X[i];
    for(int i=0;i<N;i++)
    {
        long long Ans=X[i];
        int mn=X[i];
        for(int j=i-1;j>=0;j--)
        {
            Ans+=min(mn,X[j]);
            mn=min(mn,X[j]);
        }
        mn=X[i];
        for(int j=i+1;j<N;j++)
        {
            Ans+=min(mn,X[j]);
            mn=min(mn,X[j]);
        }
        if(Ans>mx)
        {
            mx=Ans;
            p=i;
        }
    }
    int mn=X[p];
    for(int j=p-1;j>=0;j--)
    {
        X[j]=min(mn,X[j]);
        mn=min(mn,X[j]);
    }
    mn=X[p];
    for(int j=p+1;j<N;j++)
    {
        X[j]=min(mn,X[j]);
        mn=min(mn,X[j]);
    }
    for(int i=0;i<N;i++)
        cout<<X[i]<<" ";
    return 0;
}