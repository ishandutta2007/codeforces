#include <iostream>
#define DMAX 1000000
using namespace std;

long long x;
long long m[DMAX];
long long t;
string s;

int main()
{
cin>>t;

    for(long long i=1;i<=t;i++)
    {
        cin>>s>>x;
        if(s=="?")
        {
            long long ans=0;
            long long p2=1;
            while(x)
            {
                ans=ans+(x%10)*p2;
                x/=10;
                p2*=2;
            }
            cout<<m[ans]<<'\n';
        }
        else if(s=="+")
        {
            long long nrc=0;
            long long p2=1;
            for(long long i=1;i<=19;i++)
            {
                nrc=nrc+p2*(x%2);
                p2*=2;
                x/=10;
            }
            m[nrc]++;
        }
        else{
            long long nrc=0;
            long long p2=1;
            for(long long i=1;i<=19;i++)
            {
                nrc=nrc+p2*(x%2);
                p2*=2;
                x/=10;
            }
            m[nrc]--;
        }
    }


    return 0;
}