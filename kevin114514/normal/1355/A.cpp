#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long A,B;
        cin>>A>>B;
        bool ended=false;
        while(--B)
        {
            long long Min=9,Max=0;
            long long Copy=A;
            while(Copy)
            {
                long long X=Copy%10ll;
                Copy/=10ll;
                Min=min(Min,X);
                Max=max(Max,X);
            }
            //cout<<A<<" "<<Min<<" "<<Max<<endl;
            if(Min==0)
            {
                cout<<A<<endl;
                ended=true;
                break;
            }
            A+=Min*Max;
        }
        if(!ended)
            cout<<A<<endl;
    }
    return 0;
}