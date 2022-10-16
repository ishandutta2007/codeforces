#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    int N;
    cin>>S>>N;
    while(N--)
    {
        if(S[S.length()-1]=='0')
            S=S.substr(0,S.length()-1);
        else    S[S.length()-1]--;
    }
    cout<<S<<endl;
    return 0;
}