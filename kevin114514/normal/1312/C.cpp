#include<bits/stdc++.h>
using namespace std;
long long X[33];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        long long K;
        cin>>N>>K;
        for(int i=0;i<N;i++)
            cin>>X[i];
        bool ok=true;
        bool Ans=true;
        while(ok)
        {
            ok=false;
            long long Cnt=0;
            for(int i=0;i<N;i++)
            {
                Cnt+=X[i]%K;
                X[i]/=K;
                if(X[i])
                    ok=true;
            }
            if(Cnt>1)
            {
                Ans=false;
                break;
            }
        }
        if(Ans)
            puts("YES");
        else    puts("NO");
    }
    return 0;
}