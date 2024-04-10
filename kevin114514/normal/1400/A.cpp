#include<bits/stdc++.h>
using namespace std;
bool have[55][2];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(have,0,sizeof(have));
        int N;
        cin>>N;
        string S;
        cin>>S;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                have[j][S[i+j]-'0']=true;
        for(int i=0;i<N;i++)
            if(have[i][0]&&!have[i][1])
                cout<<0;
            else    cout<<1;
        puts("");
    }
    return 0;
}