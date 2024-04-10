#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[4];
    for(int i=0;i<4;i++)
        cin>>A[i];
    string S;
    cin>>S;
    int Ans=0;
    for(int i=0;i<S.length();i++)
        Ans+=A[S[i]-'1'];
    cout<<Ans<<endl;
    return 0;
}