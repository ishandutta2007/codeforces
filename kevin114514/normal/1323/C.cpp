#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    string S;
    cin>>S;
    int X=0;
    for(int i=0;i<N;i++)
        if(S[i]==')')
            X--;
        else    X++;
    if(X)
    {
        puts("-1");
        return 0;
    }
    int Ans=0,cnt=0;
    for(int i=0;i<N;i++)
    {
        int Tmp=-1;
        if(S[i]=='(')
            Tmp+=2;
        if(X+Tmp==0)
        {
            if(Tmp==1)
            {
                Ans+=cnt+1;
                cnt=0;
            }
            else    cnt=0;
        }
        else    cnt++;
        X+=Tmp;
    }
    cout<<Ans<<endl;
    return 0;
}