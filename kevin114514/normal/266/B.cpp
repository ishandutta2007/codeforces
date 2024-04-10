#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    while(K--)
    {
        for(int i=0;i<N-1;i++)
            if(S[i]=='B'&&S[i+1]=='G')
            {
                swap(S[i],S[i+1]);
                i++;
            }
    }
    cout<<S<<endl;
    return 0;
}