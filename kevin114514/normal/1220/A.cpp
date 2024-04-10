#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,cnt=0;
    string S;
    cin>>N>>S;
    for(int i=0;i<N;i++)
        if(S[i]=='n')
        {
            cout<<1<<" ";
            cnt++;
        }
    for(int i=0;i<(N-cnt*3)/4;i++)
        cout<<0<<" ";
    return 0;
}