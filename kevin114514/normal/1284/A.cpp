#include<bits/stdc++.h>
using namespace std;
string A[22],B[22];
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<M;i++)
        cin>>B[i];
    int Q;
    cin>>Q;
    while(Q--)
    {
        int X;
        cin>>X;
        X--;
        cout<<A[X%N]<<B[X%M]<<endl;
    }
    return 0;
}