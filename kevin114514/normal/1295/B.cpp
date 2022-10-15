#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,K,enu=0;
        string S;
        cin>>N>>K>>S;
        for(int i=0;i<N;i++)
            if(S[i]=='1')
                enu--;
            else    enu++;
        int Sum=0,Ans=0;
        if(K==0)
        {
            if(enu==0)
            {
                puts("-1");
                continue;
            }
            Ans++;
        }
        bool F=false;
        for(int i=0;i<N;i++)
        {
            if(S[i]=='1')
                Sum--;
            else    Sum++;
            if(enu!=0&&(K-Sum)%enu==0&&(K-Sum)/enu>=0)
                Ans++;
            if(K==Sum&&enu==0)
            {
                F=true;
                puts("-1");
                break;
            }
        }
        if(!F)
            cout<<Ans<<endl;
    }
    return 0;
}