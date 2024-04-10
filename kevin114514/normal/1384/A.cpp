#include<bits/stdc++.h>
using namespace std;
int X;
string S[200];
int L[200];
void Solve()
{
    int N;
    cin>>N;
    for(int i=0;i<=N;i++)
        S[i]="\0";
    for(int i=1;i<=N;i++)
        cin>>L[i];
    S[0]="\0";
    S[0]+=(char)(X+'a');
    for(int i=1;i<=N;i++)
    {
        if(!L[i])
        {
            X++;
            X%=26;
            S[i]+=(char)(X+'a');
            continue;
        }
        int Len=S[i-1].length();
        if(Len>=L[i])
            S[i]=S[i-1].substr(0,L[i]);
        else
        {
            X++;
            X%=26;
            for(int j=Len+1;j<=L[i];j++)
                S[i-1]+=(char)(X+'a');
            S[i]=S[i-1];
        }
    }
    for(int i=0;i<=N;i++)
        puts(S[i].c_str());
    return ;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        Solve();
    return 0;
}