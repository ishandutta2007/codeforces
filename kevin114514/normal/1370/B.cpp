#include<bits/stdc++.h>
using namespace std;
int X[2020];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=0;i<N+N;i++)
            cin>>X[i];
        int Odd=0;
        for(int i=0;i<N+N;i++)
            if(X[i]%2)
                Odd++;
        bool f=false;
        if(Odd%2)
            f=true;
        int Even=N+N-Odd;
        Odd/=2;
        Odd*=2;
        if(Even==0)
        	Odd-=2;
        for(int i=0;i<N+N&&Odd;i++)
            if(X[i]%2)
            {
                cout<<i+1;
                if(Odd%2)
                    puts("");
                else    cout<<" ";
                Odd--;
            }
        Even/=2;
        Even*=2;
        if(!f)
            Even-=2;
        for(int i=0;i<N+N&&Even;i++)
            if(X[i]%2==0)
            {
                cout<<i+1;
                if(Even%2)
                    puts("");
                else    cout<<" ";
                Even--;
            }
    }
    return 0;
}