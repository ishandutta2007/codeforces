#include<bits/stdc++.h>
using namespace std;
int x[110];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,X;
        cin>>N>>X;
        for(int i=0;i<N;i++)
            cin>>x[i];
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=x[i];
        if(sum==X)
            puts("NO");
        else
        {
            puts("YES");
            for(int i=0;i<N;i++)
                if(X==x[i])
                {
                    cout<<x[i+1]<<" "<<x[i]<<" ";
                    X-=x[i+1];
                    X-=x[i];
                    i++;
                }
                else
                {
                    cout<<x[i]<<" ";
                    X-=x[i];
                }
            puts("");
        }
    }
    return 0;
}