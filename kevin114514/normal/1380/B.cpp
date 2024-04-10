#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        int RR=0,SS=0,PP=0;
        for(int i=0;i<S.length();i++)
            if(S[i]=='S')
                SS++;
            else if(S[i]=='P')
                PP++;
            else    RR++;
        int MMAAXX=max(max(RR,SS),PP);
        if(RR==MMAAXX)
        {
            for(int i=0;i<S.length();i++)
                cout<<"P";
            puts("");
        }
        else if(SS==MMAAXX)
        {
            for(int i=0;i<S.length();i++)
                cout<<"R";
            puts("");
        }
        else
        {
            for(int i=0;i<S.length();i++)
                cout<<"S";
            puts("");
        }
    }
    return 0;
}