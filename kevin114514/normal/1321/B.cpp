#include<bits/stdc++.h>
using namespace std;
long long X[600600];
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        X[x-i+N]+=x;
    }
    long long Ans=0;
    for(int i=0;i<600600;i++)
        Ans=max(Ans,X[i]);
    cout<<Ans<<endl;
    return 0;
}