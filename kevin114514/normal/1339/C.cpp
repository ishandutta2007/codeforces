#include<bits/stdc++.h>
using namespace std;
long long pw2[35];
long long X[100100];
int main()
{
    pw2[0]=1ll;
    for(int i=1;i<35;i++)
        pw2[i]=pw2[i-1]*2ll;
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>X[i];
        int mx=0;
        for(int i=1;i<N;i++)
        {
            int j;
            for(j=mx;j<35;j++)
                if(X[i]+pw2[j]-1>=X[i-1])
                {
                    mx=j;
                    break;
                }
            X[i]=max(X[i-1],X[i]);
        }
        cout<<mx<<endl;
    }
    return 0;
}