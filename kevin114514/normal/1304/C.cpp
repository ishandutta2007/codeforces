#include<bits/stdc++.h>
using namespace std;
int T[110],L[110],H[110];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin>>N>>K;
        N++;
        L[0]=H[0]=K;
        bool OK=true;
        for(int i=1;i<N;i++)
            cin>>T[i]>>L[i]>>H[i];
        for(int i=0;i<N&&OK;i++)
            for(int j=i+1;j<N&&OK;j++)
            {
                if(L[i]>H[j])
                    if(L[i]-H[j]>T[j]-T[i])
                        OK=false;
                if(H[i]<L[j])
                    if(L[j]-H[i]>T[j]-T[i])
                        OK=false;
            }
        if(OK)
            puts("YES");
        else    puts("NO");
    }
}