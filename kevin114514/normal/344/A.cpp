#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S="JPY4SB",T;
    int N,Ans=0;
    cin>>N;
    while(N--)
    {
        cin>>T;
        if(S!=T)
            Ans++;
        S=T;
    }
    cout<<Ans<<endl;
}