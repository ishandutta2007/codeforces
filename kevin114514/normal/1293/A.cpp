#include<bits/stdc++.h>
using namespace std;
int X[1010],Y[1010];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,S,K;
        cin>>N>>S>>K;
        for(int i=0;i<K;i++)
        {
            cin>>X[i];
            Y[i+1]=0;
            X[i]=abs(X[i]-S);
        }
        for(int i=1;i<=K;i++)
        {
            if(S>i)
                Y[i]++;
            if(N-S>=i)
                Y[i]++;
        }
        sort(X,X+K);
        if(X[0])
            cout<<0<<endl;
        else
        {
            for(int i=1;i<K;i++)
            {
                if(X[i]>K)
                    break;
                else    Y[X[i]]--;
            }
            for(int i=1;i<=K;i++)
                if(Y[i])
                {
                    cout<<i<<endl;
                    break;
                }
        }
    }
    return 0;
}