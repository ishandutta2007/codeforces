#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int Sum=0;
        int Ans=0;
        while(N--)
        {
            int X;
            cin>>X;
            Sum+=X;
            if(X==0)
            {
                Ans++;
                Sum++;
            }
        }
        if(Sum==0)
            Ans++;
        cout<<Ans<<endl;
    }
    return 0;
}