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
        int Ans=0;
        int Cnt=0;
        for(int i=0;i<S.length();i++)
        {
            Cnt++;
            if(S[i]=='R')
            {
                Ans=max(Ans,Cnt);
                Cnt=0;
            }
        }
        Cnt++;
        Ans=max(Ans,Cnt);
        cout<<Ans<<endl;
    }
    return 0;
}