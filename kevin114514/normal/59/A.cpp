#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin>>S;
    int cntl=0,cntu=0;
    for(int i=0;i<S.length();i++)
        if(isupper(S[i]))
            cntu++;
        else    cntl++;
    if(cntl>=cntu)
    {
        for(int i=0;i<S.length();i++)
            if(isupper(S[i]))
                S[i]+='a'-'A';
    }
    else
    {
        for(int i=0;i<S.length();i++)
            if(islower(S[i]))
                S[i]+='A'-'a';
    }
    cout<<S<<endl;
    return 0;
}