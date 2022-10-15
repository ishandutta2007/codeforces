#include<bits/stdc++.h>
using namespace std;
int X[110];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>X[i];
        bool f=false;
        for(int i=0;i<N;i++)
            if(X[i]%2==0)
            {
                f=true;
                cout<<1<<endl<<i+1<<endl;
                break;
            }
        if(f)
            continue;
        if(N>1)
        {
            f=true;
            cout<<2<<endl<<1<<" "<<2<<endl;
        }
        else
            puts("-1");
    }
    return 0;
}